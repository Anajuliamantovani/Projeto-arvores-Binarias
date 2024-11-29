#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arvores.h"

usuario *Usuario = NULL;

int tamanho;
int posicao;
int NumRegistro;

int adicionar(int Id)
{
    expand();
    printf("CPF:");
    fgets(Usuario[Id].CPF, 30, stdin);
    Usuario[Id].CPF[strcspn(Usuario[Id].CPF,"\n")] = '\0';


    if(Id != 0)
    {
        for (int i = 0; i < Id ; i++)
        {
            if(i != Id)
            {
                if(strcmp(Usuario[i].CPF, Usuario[Id].CPF) == 0)
                {
                    printf("CPF ja Cadastrado.");
                    return Id;
                }
            }
        }
    }

    printf("Preencha as informacoes a seguir:\n");

    printf("Nome:");
    fgets(Usuario[Id].nome, 80, stdin);
    Usuario[Id].nome[strcspn(Usuario[Id].nome,"\n")] = '\0';

    printf("Endereco:");
    fgets(Usuario[Id].endereço, 100, stdin);
    Usuario[Id].endereço[strcspn(Usuario[Id].endereço,"\n")] = '\0';

    printf("Telefone:");
    fgets(Usuario[Id].telefone, 30, stdin);
    Usuario[Id].telefone[strcspn(Usuario[Id].telefone,"\n")] = '\0';

    printf("E-mail:");
    fgets(Usuario[Id].email, 100, stdin);
    Usuario[Id].email[strcspn(Usuario[Id].email,"\n")] = '\0';

    NumRegistro++;
    Id++;
    tamanho = Id;
    posicao = Id;
    return Id;
    return 0;
}

void expand() // funcao para criar um novo espaco na memoria sem que
{
    usuario *temp; // o ponteiro temp do tipo usuario, esta dizendo para  aumentar o tamanho do vetor, assim tendo mais espaco para cadastrar usuarios

    printf("Expandindo...\n");

    tamanho = tamanho + 5;

    temp = malloc(tamanho * sizeof(usuario)); // aloca memoria para o novo vetor com o novo tamanho
    if(!temp) {
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < posicao; i++)
    {
        temp[i] = Usuario[i];
    }

    free(Usuario);
    Usuario = temp;
}

void Alterar()
{

}

void Escolher()
{

}

void Excluir()
{

}

void Procurar()
{

}

void Relatorio()
{

}

void Sair ()
{

}

int printarEscolha(int Id)
{
    if(strcmp(Usuario[Id].CPF, " ") != 0)

    {
        printf("\n");
        printf("Nome: %s\n", Usuario[Id].nome);
        printf("Endereco: %s\n", Usuario[Id].endereço);
        printf("CPF: %s\n", Usuario[Id].CPF);
        printf("Telefone: %s\n", Usuario[Id].telefone);
        printf("E-mail: %s\n", Usuario[Id].email);
        printf("\n");
    }
    return 0;
}

int PrintAll(int id)
{
    for (int i = 0; i < id ; ++i)
    {
        printarEscolha(i);
    }
    return 0;
}


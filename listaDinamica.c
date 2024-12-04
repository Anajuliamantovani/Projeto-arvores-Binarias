#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDinamica.h"
#include "listaLigada.h"
#include "arvoreBinaria.h"

usuario *Usuario = NULL;

int tamanho;
int posicao;
int NumRegistro;
char tempCPF[30];
int tempNRegistro;

int adicionar(int Id)
{
    expand();
    int verificando = procurarCpf(Id);
    if(verificando == 1)
    {
        return Id;
    }

    int tempCpf = 0;
    sscanf(Usuario[Id].CPF, "%d", &tempCpf);

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


    ABaux = ABnovoNo(tempCpf, NumRegistro);
    ABadicionar(ABaux,ABinicio);

    LLadicionar(Usuario[Id].nome, NumRegistro);

    NumRegistro++;
    Id++;
    tamanho = Id;
    posicao = Id;
    return Id;
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
    if(procurarCpf(-1) == 0)
    {
        return;
    }
    ABexcluir(tempCPF);
    LLexcluir(tempNRegistro);
}

void Procurar()
{
    if(procurarCpf(-1) == 0)
    {
        return;
    }

    printarEscolha(tempNRegistro);

    /*
    for (int x = 0; x < NumRegistro; x++)
    {
        if(strcmp(tempCPF, Usuario[x].CPF) == 0)
        {

           printarEscolha(x);

        }
    }
    */

}

void Relatorio()
{
    LLimprimir();
}

void Sair ()
{

}

int printarEscolha(int Id)
{

        printf("\n");
        printf("Nome: %s\n", Usuario[Id].nome);
        printf("Endereco: %s\n", Usuario[Id].endereço);
        printf("CPF: %s\n", Usuario[Id].CPF);
        printf("Telefone: %s\n", Usuario[Id].telefone);
        printf("E-mail: %s\n", Usuario[Id].email);
        printf("\n");

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



int procurarCpf(int par_Id)
{

    int tempCpf = 0;
    printf("CPF:");

    if(par_Id != -1)
    {
         fgets(Usuario[par_Id].CPF, 30, stdin);
         Usuario[par_Id].CPF[strcspn(Usuario[par_Id].CPF,"\n")] = '\0';
         sscanf(Usuario[par_Id].CPF, "%d", &tempCpf);
    }
    else
    {
        fgets(tempCPF, 30, stdin);
        tempCPF[strcspn(tempCPF,"\n")] = '\0';
        sscanf(tempCPF, "%d", &tempCpf);
    }

    if(par_Id != 0)
    {

        ABaux = ABlocalizar(tempCpf, ABinicio);



        if(ABaux == NULL)
        {
            printf("CPF nao encontrado!\n");
            return 0;
        }
        else
        {
            printf("CPF ja cadastrado \n");
            tempNRegistro = ABaux->NumRegistro;
            return 1;
        }
    }

    return 0;

}


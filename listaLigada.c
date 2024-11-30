/*//
// Created by JoaoV on 30/11/2024.
//
#include "listaLigada.h"
#include "listaDinamica.h"
#include "arvoreBinaria.h"

struct noLigada *novoNo(char nome[80], int NRegistro) {
    struct noLigada *p = malloc(sizeof(struct noLigada));
    if(!p) {
        printf("Erro na alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
    //p->nome = nome;
    strcpy(p->nome, nome);
    p->NRegistro = NRegistro;
    p->proximo = NULL;

    return p;
}

void LLadicionar(char nome[80], int NRegistro)
{
    novo = novoNo(nome, NRegistro);

    if(inicio == NULL) {
        inicio = novo;
    }
    else {
        //novo->NRegistro < inicio->NRegistro
        //strcmp comparar duas string em ordem alfabetica
        if(strcmp(novo->nome , inicio->nome) < 0) {
            adicionarNoInicio();
        }
        else {
            aux = inicio;
            anterior = inicio;

            while(strcmp(aux->nome , novo->nome) < 0 && aux->proximo != NULL) {
                anterior = aux;
                aux = aux->proximo;
            }

            if(strcmp(novo->nome , aux->nome) > 0) {
                adicionarNoFinal();
            }
            else {
                adicionarNoMeio();
            }
        }
    }
}

void adicionarNoInicio() {
    novo->proximo = inicio;
    inicio = novo;
}

void adicionarNoFinal() {
    aux->proximo = novo;
}

void adicionarNoMeio() {
    novo->proximo = aux;
    anterior->proximo = novo;
}
*/


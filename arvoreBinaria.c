//
// Created by JoaoV on 30/11/2024.
//
#include "listaLigada.h"
#include "listaDinamica.h"
#include "arvoreBinaria.h"

struct noArvore *ABnovoNo(int CPF, int NumRegistro)
{
    struct noArvore *p = malloc(sizeof(struct noArvore));
    if(!p) {
        printf("Erro ao alocar no memoria\n");
        exit(EXIT_FAILURE);
    }
    p->esquerda = NULL;
    p->CPF = CPF;
    p->NumRegistro = NumRegistro;
    p->direita = NULL;

    return p;
}

void ABadicionar(struct noArvore *Aux, struct noArvore *Inicio)
{
    if(inicio == NULL)
    {
        printf("Adicionando %d no inicio\n",Aux->CPF);
        inicio = Aux;
    }
    else
    {
        if(Aux->CPF > Inicio->CPF)
            {
            // adicionar na direita
            if(Inicio->direita == NULL)
            {
                printf("Adicionando %d a direita de %d\n",Aux->CPF, Inicio->CPF);
                Inicio->direita = Aux;
            }
            else
            {
                printf("Indo para a direita de %d\n", Inicio->CPF);
                ABadicionar(Aux, Inicio->direita);
            }
        }
        else
        {
            // adicionar na esquerda
            if(Inicio->esquerda == NULL)
            {
                printf("Adicionando %d a esquerda de %d\n",Aux->CPF, Inicio->CPF);
                Inicio->esquerda = Aux;
            }
            else
            {
                printf("Indo para a esquerda de %d\n", Inicio->CPF);
                ABadicionar(Aux, Inicio->esquerda);
            }
        }
    }
}

struct noArvore *localizar(int CPF, struct noArvore *Inicio)
{
    if(Inicio->CPF == CPF)
    {
        //printf("CPF ja cadastrado %d\n", CPF);
        return Inicio;
    }
    else {
        if(CPF > Inicio->CPF)
        {
            // procurar na direita
            if(Inicio->direita != NULL)
            {
                anterior = Inicio;
                //printf("Indo para a direita de %d\n", Inicio->CPF);
                return localizar(CPF, Inicio->direita);
            }
            else
            {
                //printf("CPF nao encontrado %d!\n", CPF);
                return NULL;
            }
        }
        else
        {
            // procurar na esquerda
            if(Inicio->esquerda != NULL)
            {
                anterior = Inicio;
                //printf("Indo para a esquerda de %d\n", Inicio->CPF);
                return localizar(CPF, Inicio->esquerda);
            }
            else
            {
                //printf("CPF nao encontrado %d!\n", CPF);
                return NULL;
            }
        }
    }
}

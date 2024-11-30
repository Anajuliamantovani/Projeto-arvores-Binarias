
//
// Created by JoaoV on 30/11/2024.
//
#include "listaLigada.h"
#include "listaDinamica.h"
#include "arvoreBinaria.h"

struct noArvore *Ainicio;
struct noArvore *Aaux;
struct noArvore *Aanterior;
struct noArvore *Aproximo;


void inicializar()
{
    Ainicio = NULL;
}

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
    if(Inicio == NULL)
    {
        printf("Adicionando %d no inicio\n",Aux->CPF);
        Inicio = Aux;
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

struct noArvore *ABlocalizar(int CPF, struct noArvore *Inicio)
{
    printf('teste');
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
                Aanterior = Inicio;
                //printf("Indo para a direita de %d\n", Inicio->CPF);
                return ABlocalizar(CPF, Inicio->direita);
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
                Aanterior = Inicio;
                //printf("Indo para a esquerda de %d\n", Inicio->CPF);
                return ABlocalizar(CPF, Inicio->esquerda);
            }
            else
            {
                //printf("CPF nao encontrado %d!\n", CPF);
                return NULL;
            }
        }
    }
}


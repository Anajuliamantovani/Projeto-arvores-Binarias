
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
    LLinicio = NULL;
}

struct noArvore *ABnovoNo(int par_CPF, int par_NumRegistro)
{
    struct noArvore *p = malloc(sizeof(struct noArvore));
    if(!p) {
        printf("Erro ao alocar no memoria\n");
        exit(EXIT_FAILURE);
    }
    p->esquerda = NULL;
    p->CPF = par_CPF;
    p->NumRegistro = par_NumRegistro;
    p->direita = NULL;

    return p;
}

void ABadicionar(struct noArvore *par_Aux, struct noArvore *par_Inicio)
{
    if(Ainicio == NULL)
    {
        //printf("Adicionando %d no inicio\n",par_Aux->CPF);
        Ainicio = par_Aux;
    }
    else
    {
        if(par_Aux->CPF > par_Inicio->CPF)
            {
            // adicionar na direita
            if(par_Inicio->direita == NULL)
            {
               // printf("Adicionando %d a direita de %d\n",par_Aux->CPF, par_Inicio->CPF);
                par_Inicio->direita = par_Aux;
            }
            else
            {
                //printf("Indo para a direita de %d\n", par_Inicio->CPF);
                ABadicionar(par_Aux, par_Inicio->direita);
            }
        }
        else
        {
            // adicionar na esquerda
            if(par_Inicio->esquerda == NULL)
            {
               // printf("Adicionando %d a esquerda de %d\n",par_Aux->CPF, par_Inicio->CPF);
                par_Inicio->esquerda = par_Aux;
            }
            else
            {
                //printf("Indo para a esquerda de %d\n", par_Inicio->CPF);
                ABadicionar(par_Aux, par_Inicio->esquerda);
            }
        }
    }
}

/*struct noArvore *ABlocalizar(int par_cpf, struct noArvore *par_inicio)
{
    if(par_inicio->CPF == par_cpf) {
        printf("Achei %d\n", par_cpf);
        return par_inicio;
    }
    else {
        if(par_cpf > par_inicio->CPF) {
            // procurar na direita
            if(par_inicio->direita != NULL) {
                Aanterior = par_inicio;
                printf("Indo para a direita de %d\n", par_inicio->CPF);
                return ABlocalizar(par_cpf , par_inicio->direita);
            }
            else {
                printf("Nao achei %d!\n", par_cpf);
                return NULL;
            }
        }
        else {
            // procurar na esquerda
            if(par_inicio->esquerda != NULL) {
                Aanterior = par_inicio;
                printf("Indo para a esquerda de %d\n", par_inicio->CPF);
                return ABlocalizar(par_cpf, par_inicio->esquerda);
            }
            else {
                printf("Nao achei %d!\n", par_cpf);
                return NULL;
            }
        }
    }
}*/

struct noArvore *ABlocalizar(int par_cpf, struct noArvore *par_inicio)
{
    if (par_inicio == NULL) {
       // printf("Nao achei %d! A arvore está vazia ou chegamos a um nó inexistente.\n", par_cpf);
        return NULL;
    }

    if (par_inicio->CPF == par_cpf) {
        //printf("Achei %d\n", par_cpf);
        return par_inicio;
    }

    if (par_cpf > par_inicio->CPF) {
        // procurar na direita
        //printf("Indo para a direita de %d\n", par_inicio->CPF);
        return ABlocalizar(par_cpf, par_inicio->direita);
    } else {
        // procurar na esquerda
        //printf("Indo para a esquerda de %d\n", par_inicio->CPF);
        return ABlocalizar(par_cpf, par_inicio->esquerda);
    }
}



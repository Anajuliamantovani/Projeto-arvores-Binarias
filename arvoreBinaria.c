
//
// Created by JoaoV on 30/11/2024.
//
#include "listaLigada.h"
#include "listaDinamica.h"
#include "arvoreBinaria.h"

struct noArvore *ABinicio;
struct noArvore *ABaux;
struct noArvore *ABanterior;
struct noArvore *ABproximo;


void inicializar()
{
    ABinicio = NULL;
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
    if(ABinicio == NULL)
    {
        //printf("Adicionando %d no inicio\n",par_Aux->CPF);
        ABinicio = par_Aux;
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

void ABexcluir(int dado) {
    if(ABinicio == NULL) {
        return;
    }
    else {
        ABaux = ABlocalizar(dado, ABinicio);
        if(ABaux != NULL) {
            if(ABaux == ABinicio) {
                ABinicio = NULL;
            }
            else {
                if(ABaux->CPF > ABanterior->CPF) {
                    ABanterior->direita = NULL;
                }
                else {
                    ABanterior->esquerda = NULL;
                }
            }
            if(ABaux->esquerda != NULL) {
                ABadicionar(ABaux->esquerda, ABinicio);
            }
            if(ABaux->direita != NULL) {
                ABadicionar(ABaux->direita, ABinicio);
            }
            free(ABaux);
        }
    }
}



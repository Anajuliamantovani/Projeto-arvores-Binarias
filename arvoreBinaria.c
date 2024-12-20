
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
        ABinicio = par_Aux;
    }
    else
    {
        if(par_Aux->CPF > par_Inicio->CPF)
            {
            // adicionar na direita
            if(par_Inicio->direita == NULL)
            {
                par_Inicio->direita = par_Aux;
            }
            else
            {
                ABadicionar(par_Aux, par_Inicio->direita);
            }
        }
        else
        {
            // adicionar na esquerda
            if(par_Inicio->esquerda == NULL)
            {
                par_Inicio->esquerda = par_Aux;
            }
            else
            {
                ABadicionar(par_Aux, par_Inicio->esquerda);
            }
        }
    }
}

struct noArvore *ABlocalizar(int par_cpf, struct noArvore *par_inicio)
{
    if (par_inicio == NULL) {

        return NULL;
    }

    if (par_inicio->CPF == par_cpf) {

        return par_inicio;
    }

    if (par_cpf > par_inicio->CPF) {
        // procurar na direita

        return ABlocalizar(par_cpf, par_inicio->direita);
    } else {
        // procurar na esquerda
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

void ABfinalizar(struct noArvore *par_quem)
{
    if(par_quem == NULL) {
        return;
    }
    if(par_quem->esquerda != NULL) {

        ABfinalizar(par_quem->esquerda);
    }
    if(par_quem->direita != NULL) {

        ABfinalizar(par_quem->direita);
    }
    printf("Excluindo %d...\n",par_quem->CPF);
    free(par_quem);
}


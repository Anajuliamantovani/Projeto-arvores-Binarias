//
// Created by JoaoV on 30/11/2024.
//
#include "listaLigada.h"
#include "listaDinamica.h"
#include "arvoreBinaria.h"

 struct noLigada *LLinicio;
 struct noLigada *LLaux;
 struct noLigada *LLanterior;
 struct noLigada *LLproximo;
 struct noLigada *LLnovo;
 struct noLigada *LLnoCorrente;

struct noLigada *LLnovoNo(char par_nome[80], int par_NRegistro) {
    struct noLigada *p = malloc(sizeof(struct noLigada));
    if(!p) {
        printf("Erro na alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
    //p->nome = nome;
    strcpy(p->nome, par_nome);
    p->NRegistro = par_NRegistro;
    p->proximo = NULL;

    return p;
}

void LLadicionar(char par_nome[80], int par_NRegistro)
{
    LLnovo = LLnovoNo(par_nome, par_NRegistro);

    if(LLinicio == NULL) {
        LLinicio = LLnovo;
    }
    else {
        //novo->NRegistro < inicio->NRegistro
        //strcmp comparar duas string em ordem alfabetica
        if(strcmp(LLnovo->nome , LLinicio->nome) < 0) {
            LLadicionarNoInicio();
        }
        else {
            LLaux = LLinicio;
            LLanterior = LLinicio;

            while(strcmp(LLaux->nome , LLnovo->nome) < 0 && LLaux->proximo != NULL) {
                LLanterior = LLaux;
                LLaux = LLaux->proximo;
            }

            if(strcmp(LLnovo->nome , LLaux->nome) > 0) {
                LLadicionarNoFinal();
            }
            else {
                LLadicionarNoMeio();
            }
        }
    }
}

void LLadicionarNoInicio() {
    LLnovo->proximo = LLinicio;
    LLinicio = LLnovo;
}

void LLadicionarNoFinal() {
    LLaux->proximo = LLnovo;
}

void LLadicionarNoMeio() {
    LLnovo->proximo = LLaux;
    LLanterior->proximo = LLnovo;
}


bool LLcorrente(int *dado) {
    if(LLnoCorrente == NULL) {
        return false;
    }
    *dado = LLnoCorrente->NRegistro;

    return true;
}

bool LLparaProximo() {
    if(LLnoCorrente == NULL) {
        return false;
    }
    LLnoCorrente = LLnoCorrente->proximo;

    return true;
}

void LLparaInicio() {
    LLnoCorrente = LLinicio;
}

void LLimprimir() {
    int valor = 0;
    if(LLinicio != NULL) {
        LLparaInicio();
        while(LLcorrente(&valor)) {
            printarEscolha(valor);
            LLparaProximo();
        }
        printf("\n");
    }
}

void LLexcluir(int par_dado) {
    if(LLinicio != NULL) {
        if(par_dado == LLinicio->NRegistro) {
            LLexcluirNoInicio();
        }
        else {
            LLaux = LLinicio;
            LLanterior = LLinicio;
            while(LLaux->NRegistro != par_dado && LLaux->proximo != NULL) {
                LLanterior = LLaux;
                LLaux = LLaux->proximo;
            }
            if(LLaux->NRegistro == par_dado) {
                if(LLaux->proximo == NULL) {
                    LLexcluirNoFinal();
                }
                else {
                    LLexcluirNoMeio();
                }
            }
        }
    }
}

void LLexcluirNoInicio() {
    if(LLinicio->proximo == NULL) {
        free(LLinicio);
        LLinicio = NULL;
    }
    else {
        LLaux = LLinicio;
        LLinicio = LLinicio->proximo;
        free(LLaux);
    }
}

void LLexcluirNoFinal() {
    LLanterior->proximo = NULL;
    free(LLaux);
}

void LLexcluirNoMeio() {
    LLproximo = LLaux->proximo;

    LLanterior->proximo = LLproximo;
    free(LLaux);
}



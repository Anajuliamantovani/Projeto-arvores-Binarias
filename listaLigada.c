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
            adicionarNoInicio();
        }
        else {
            LLaux = LLinicio;
            LLanterior = LLinicio;

            while(strcmp(LLaux->nome , LLnovo->nome) < 0 && LLaux->proximo != NULL) {
                LLanterior = LLaux;
                LLaux = LLaux->proximo;
            }

            if(strcmp(LLnovo->nome , LLaux->nome) > 0) {
                adicionarNoFinal();
            }
            else {
                adicionarNoMeio();
            }
        }
    }
}

void adicionarNoInicio() {
    LLnovo->proximo = LLinicio;
    LLinicio = LLnovo;
}

void adicionarNoFinal() {
    LLaux->proximo = LLnovo;
}

void adicionarNoMeio() {
    LLnovo->proximo = LLaux;
    LLanterior->proximo = LLnovo;
}



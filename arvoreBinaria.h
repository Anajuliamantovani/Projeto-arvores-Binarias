#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noArvore
{
    int CPF;
    int NumRegistro;
    struct noArvore *esquerda;
    struct noArvore *direita;
};

extern struct noArvore *Ainicio;
extern struct noArvore *Aaux;
extern struct noArvore *Aanterior;
extern struct noArvore *Aproximo;


struct noArvore *localizar(int CPF, struct noArvore *Inicio);
void ABadicionar(struct noArvore *Aux, struct noArvore *Inicio);
struct noArvore *novoNo(int CPF, int NumRegistro);
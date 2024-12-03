
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noArvore
{
    struct noArvore *esquerda;
    int CPF;
    int NumRegistro;
    struct noArvore *direita;
};

extern struct noArvore *Ainicio;
extern struct noArvore *Aaux;
extern struct noArvore *Aanterior;
extern struct noArvore *Aproximo;


struct noArvore *ABlocalizar(int par_cpf, struct noArvore *par_inicio);
void ABadicionar(struct noArvore *par_Aux, struct noArvore *par_Inicio);
struct noArvore *ABnovoNo(int par_CPF, int par_NumRegistro);
void inicializar();



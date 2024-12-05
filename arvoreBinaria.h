
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

extern struct noArvore *ABinicio;
extern struct noArvore *ABaux;
extern struct noArvore *ABanterior;
extern struct noArvore *ABproximo;


struct noArvore *ABlocalizar(int par_cpf, struct noArvore *par_inicio);
void ABadicionar(struct noArvore *par_Aux, struct noArvore *par_Inicio);
struct noArvore *ABnovoNo(int par_CPF, int par_NumRegistro);
void inicializar();
void ABexcluir(int dado);
void ABfinalizar(struct noArvore *par_quem);



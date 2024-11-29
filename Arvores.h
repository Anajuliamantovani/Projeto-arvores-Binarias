#ifndef Arvores_h
#define Arvores_h

int adicionar(int Id);
void expand();
int PrintAll(int id);
int printarEscolha(int Id);

struct Pessoa
{
    char nome[80];
    char endereço[100];
    char CPF[30];
    char telefone[30];
    char email[80];
};

typedef struct Pessoa usuario;

struct no
{
    char nome [80];
    int NRegistro;
    struct no *proximo;
};

extern struct no *inicio;
extern struct no *aux;
extern struct no *anterior;
extern struct no *proximo;

struct NoArvore
{
    int CPF;
    int NumRegistro;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
};

#endif

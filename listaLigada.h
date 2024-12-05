#include <stdbool.h>

struct noLigada
{
    char nome [80];
    int NRegistro;
    struct noLigada *proximo;
};

extern struct noLigada *LLinicio;
extern struct noLigada *LLaux;
extern struct noLigada *LLanterior;
extern struct noLigada *LLproximo;
extern struct noLigada *LLnovo;
extern struct noLigada *LLnoCorrente;

struct noLigada *LLnovoNo(char par_nome[80], int par_NRegistro);
void LLadicionar(char par_nome[80], int par_NRegistro);
void LLadicionarNoInicio();
void LLadicionarNoFinal();
void LLadicionarNoMeio();
void LLparaInicio();
bool LLcorrente(int *dado);
bool LLparaProximo();
void LLimprimir();

void LLexcluir(int par_dado);
void LLexcluirNoInicio();
void LLexcluirNoFinal();
void LLexcluirNoMeio();
char *pMais(char *str);



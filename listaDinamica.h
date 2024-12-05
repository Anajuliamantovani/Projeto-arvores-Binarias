

int adicionar(int Id);
void expand();
int PrintAll(int id);
int printarEscolha(int Id);

struct noLDinamica
{
    char nome[80];
    char endereço[100];
    char CPF[30];
    char telefone[30];
    char email[80];
};

void Procurar();
int procurarCpf(int par_Id);
void Relatorio();
void Excluir();
int edit(int Id);
void Alterar();
void LDdestroy();
void Sair();

typedef struct noLDinamica usuario;





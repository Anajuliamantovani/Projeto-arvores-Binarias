#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"
#include "listaLigada.h"
#include "arvoreBinaria.h"

int Id;
char opcao02[30];


int main(void)
{
    int opcao;

    printf("teste");

    printf("\n\t==========================");
    printf("\n\t|  O que deseja fazer ?  |");
    printf("\n\t==========================\n");

    printf("\t1. Adicionar\t2. Alterar\n\t3. Excluir\t\t4. Procurar\n\t5. Relatório\t6. Sair\n");
    fgets(opcao02, 30, stdin);
    sscanf(opcao02, "%d", &opcao);

    if (Id == 0)
    {
        inicializar();
    }


    switch (opcao)
    {
        case 1:
            Id = adicionar(Id);
            break;

        case 2:
            //PrintAll(Id);
            break;

        case 3:
            break;

        case 4:
            Procurar();
            break;

        case 5:
            Relatorio();
            break;

        case 6:
            return 0;
    }

    main();
    return 0;
}



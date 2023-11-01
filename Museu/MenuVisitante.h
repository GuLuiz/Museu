#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "bilheteria.h"
#include "ObrasMenu.h"

int MenuVisitante() {
    int teste;
    system("cls");
    printf("==============================================\n");
    printf("             Menu Visitante\n");
    printf("==============================================\n");
    printf("\nEscolha uma opcao:\n");
    printf("1) %-20s\n", "Bilheteria");
    printf("2) %-20s\n", "Obras");
    printf("3) %-20s\n\n", "Sair");
    printf("==============================================\n");

    scanf("%d", &teste);
    if (teste == 1)
    {
        bilheteria();
    }
    else if(teste == 2){

        obras();
    }

    return 0;
}
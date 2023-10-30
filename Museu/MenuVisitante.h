#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "bilheteria.h"

int MenuVisitante() {
    char nome[50];
    int teste;
    system("cls");
    printf("\n***********************************************");
    printf("\nMENU VISITANTE");
    printf("\n1 - Bilheteria");
    printf("\n2 - Obras");
    printf("\n3 - Sair");
    scanf("%d",&teste);
    if(teste == 1){
        bilheteria();
    }

    return 0;
}
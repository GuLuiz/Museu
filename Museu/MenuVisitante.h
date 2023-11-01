#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "obras.h"

int MenuVisitante() {
    int teste;
    system("cls");
    printf("\n***********************************************");
    printf("\nMENU VISITANTE");
    printf("\n1 - Visitar Obras");
    printf("\n2 - Sair");
    printf("\n***********************************************\n");
    scanf("%d",&teste);
    if(teste == 1){
        obras();
    }
    if(teste == 2){
    }

    return 0;
}
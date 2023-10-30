#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "LoginAdmin.h"
#include "MenuVisitante.h"


int Login(){
    int decisao;

    printf("***********************************************");
    printf("\n1 - Administrador");
    printf("\n2 - Visitantes");
    printf("\n***********************************************");
    printf("\nDigite com qual acesso você deseja seguir: ");
    scanf("%d", &decisao);
    if (decisao == 1) {
        LoginAdmin(); // Chama a função LoginAdmin
    }
    if (decisao == 2) {
        MenuVisitante(); // Chama a função LoginAdmin
    }
    return 0;
}
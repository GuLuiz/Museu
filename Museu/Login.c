#include <stdlib.h>
#include <stdio.h>
#include "LoginAdmin.h"
#include "MenuVisitante.h"

void Login()
{
    int decisao;
    do
    {
        printf("***********************************************");
        printf("\n1 - Administrador");
        printf("\n2 - Visitantes");
        printf("\n***********************************************");
        printf("\nDigite com qual acesso você deseja seguir: ");
        scanf("%d", &decisao);
        if (decisao == 1)
        {
            LoginAdmin(); // Chama a função LoginAdmin
        }
        if (decisao == 2)
        {
            MenuVisitante(); // Chama a função LoginAdmin
            
        }
        while (decisao != 1 && decisao !=2 );
            
    }
}
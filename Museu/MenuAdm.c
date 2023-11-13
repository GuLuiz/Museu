#include <stdio.h>
#include <stdlib.h>
#include "obrasAdm.h"
#include "MenuAdm.h"

void menuAdm(char login[20], char senha[20]) {
    int sair = 0;
    int obrasRetornou = 0;

    while (!sair) {
        printf("\n***********************************************");
        printf("\nMENU ADMINISTRADOR");
        printf("\n***********************************************\n");
        printf("1 - Visualizar obras");
        printf("\n2 - Visualizar questionários");
        printf("\n3 - Gerar relatórios\n");
        printf("0 - Sair\n");

        int deciMenuAdm;
        scanf("%d", &deciMenuAdm);

        switch (deciMenuAdm) {
            case 0:
                sair = 1;
                break;
            case 1:
                obrasRetornou = obrasAdm();
                break;
            case 2:
                system ("start C:\\Museu\\Museu\\output\\Questionario.txt" );
                break;
            // Adicione outros casos conforme necessário
            default:
                break;
        }
    }

    if (obrasRetornou == 1) {
        printf("\nRetornando ao Menu Administrador...\n");
        menuAdm(login, senha);  // Chama recursivamente o menuAdm se obrasRetornou for 1
    } else {
        printf("\nLogout do Menu Administrador...\n");
    }
}
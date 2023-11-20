#include <stdio.h>
#include <stdlib.h>
#include "obrasAdm.h"
#include "MenuAdm.h"
#include "Relatorio.h"


void menuAdm(char login[20], char senha[20])
{
    FILE *arquivo;
    char linha[1000];
    int sair = 0;
    int obrasRetornou = 0;

    while (!sair)
    {
        printf("\n***********************************************");
        printf("\nMENU ADMINISTRADOR");
        printf("\n***********************************************\n");
        printf("1 - Visualizar obras");
        printf("\n2 - Visualizar questionários");
        printf("\n3 - Gerar relatórios\n");
        printf("0 - Sair\n");

        int deciMenuAdm;
        scanf("%d", &deciMenuAdm);

        switch (deciMenuAdm)
        {
        case 0:
            sair = 1;
            break;
        case 1:
            obrasRetornou = obrasAdm();
            break;
        case 2:
            system("start C:\\Museu\\Museu\\output\\Questionario.txt");
            break;
        case 3:
            Relatorio();
            system("cls");
            arquivo = fopen("C:\\Museu\\Museu\\output\\relatorio.txt", "r");
            while (fgets(linha, sizeof(linha), arquivo) != NULL)
            {
                printf("%s", linha);
            }
            system("pause");
            fclose(arquivo);
            break;
        default:
            break;
        }
    }

    if (obrasRetornou == 1)
    {
        printf("\nRetornando ao Menu Administrador...\n");
        menuAdm(login, senha);
    }
    else
    {
        printf("\nLogout do Menu Administrador...\n");
    }
}
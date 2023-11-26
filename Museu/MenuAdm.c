#include <stdio.h>
#include <stdlib.h>
#include "obrasAdm.h"
#include "MenuAdm.h"
#include "Relatorio.h"
#include "backup.h"

void menuAdm(char login[20], char senha[20])
{
    FILE *arquivo;
    char linha[1000];
    int sair = 0;
    int obrasRetornou = 0;

    while (!sair)
    {
        system("pause");
        system("cls");
        printf("\n***********************************************");
        printf("\nMENU ADMINISTRADOR");
        printf("\n***********************************************\n");
        printf("1 - Visualizar obras\n");
        printf("2 - Visualizar BIlhetes\n");
        printf("3 - Gerar relatórios\n");
        printf("4 - Fazer Backup dos dados\n");
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
            system("start .\\output\\Bilhete.txt");
            break;
        case 3:
            Relatorio();
            system("cls");
            arquivo = fopen(".\\output\\relatorio.txt", "r");
            while (fgets(linha, sizeof(linha), arquivo) != NULL)
            {
                printf("%s", linha);
            }
            fclose(arquivo);
            break;
        case 4:
            criarBackup(".\\output\\relatorio.txt", "..\\Adm\\relatorio_backup.txt");
            criarBackup(".\\output\\Bilhete.txt", "..\\Adm\\bilhete_backup.txt");
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
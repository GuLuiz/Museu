#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "obrasAdm.h"

int LoginAdmin()
{
    char loginAdmin[20];
    char senhaAdmin[20];
    char login[20];
    char senha[20];
    char voltar;
    int deciMenuAdm;
    int sair = 0;
    int obrasRetornou = 0; // Variável para controlar se obrasAdm retornou

    FILE *LoginAdmin;
    FILE *SenhaAdmin;
    LoginAdmin = fopen("C:\\Museu\\Adm\\Login.txt", "r");
    SenhaAdmin = fopen("C:\\Museu\\Adm\\Senha.txt", "r");

    if (LoginAdmin == NULL || SenhaAdmin == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    fgets(loginAdmin, sizeof(loginAdmin), LoginAdmin);
    fgets(senhaAdmin, sizeof(senhaAdmin), SenhaAdmin);

    system("cls");
    while (sair == 0)
    {
        printf("\n***********************************************");
        printf("\nLOGIN ADMINISTRADOR");
        printf("\nLogin: ");
        scanf("%s", login);

        if (login[strlen(login) - 1] == '\n')
        {
            login[strlen(login) - 1] = '\0';
        }

        if (senha[strlen(senha) - 1] == '\n')
        {
            senha[strlen(senha) - 1] = '\0';
        }
        printf("\nSenha: ");
        scanf("%s", senha);
        printf("***********************************************\n");
        while (obrasRetornou == 0)
        {
            if (strcmp(login, loginAdmin) == 0 && strcmp(senha, senhaAdmin) == 0)
            {
                system("cls");
                printf("Login realizado com sucesso\n");
                printf("***********************************************\n");
                printf("           MENU ADMINISTRADOR");
                printf("\n***********************************************\n");
                printf("1 - Visualizar obras");
                printf("\n2 - Visualizar questionários");
                printf("\n3 - Gerar relatórios\n");
                printf("0 - sair\n");
                scanf("%d", &deciMenuAdm);

                switch (deciMenuAdm)
                {
                case 0:
                    obrasRetornou = 1;
                    break;
                case 1:
                    obrasRetornou = obrasAdm(); // Chama obrasAdm e recebe o retorno
                    break;
                default:
                    break;
                }
                sair++;
            }
            else
            {
                printf("Credenciais incorretas\n");
                printf("Deseja tentar novamente? s/n\n");
                scanf("%s", &voltar);
                if (voltar == 'n')
                {
                    sair++;
                }
            }
        }
    }

    fclose(LoginAdmin);
    fclose(SenhaAdmin);

    if (obrasRetornou == 1)
    {
        return 1; // Retorna 1 se obrasAdm retornou
    }
    else
    {
        return 0; // Retorna 0 se não houve retorno de obrasAdm
    }
}
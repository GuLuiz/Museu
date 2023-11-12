#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obrasAdm.h"
#include "MenuAdm.h"
#include "LoginAdmin.h"

int LoginAdmin()
{
    char loginAdmin[20];
    char senhaAdmin[20];
    char login[20];
    char senha[20];
    char voltar;
    int obrasRetornou = 0;

    FILE *LoginAdminFile;
    FILE *SenhaAdminFile;
    LoginAdminFile = fopen("C:\\Museu\\Museu\\LoginAdm\\Login.txt", "r");
    SenhaAdminFile = fopen("C:\\Museu\\Museu\\LoginAdm\\Senha.txt", "r");

    if (LoginAdminFile == NULL || SenhaAdminFile == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    fgets(loginAdmin, sizeof(loginAdmin), LoginAdminFile);
    fgets(senhaAdmin, sizeof(senhaAdmin), SenhaAdminFile);

    fclose(LoginAdminFile);
    fclose(SenhaAdminFile);

    system("cls");
    int logado = 0;
    while (1)
    {
        if (logado == 0)
        {
            printf("\n***********************************************");
            printf("\nLOGIN ADMINISTRADOR");
            printf("\nLogin: ");
            scanf(" %s", login);
            printf("\nSenha: ");
            scanf(" %s", senha);
            printf("***********************************************\n");

            if (strcmp(login, loginAdmin) == 0 && strcmp(senha, senhaAdmin) == 0)
            {
                printf("Login realizado com sucesso!\n");
                logado = 1;
                menuAdm(login, senha);
                break;
            }
            else
            {
                logado = 0;
                printf("Credenciais incorretas\n");
                printf("Deseja tentar novamente? s/n\n");
                scanf(" %c", &voltar);
                if (voltar == 'n')
                {
                    printf("\nSaindo do Login Administrador...\n");
                    break;
                }
            }
        }
    }
    return 0;
}
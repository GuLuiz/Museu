#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  
#include "obrasAdm.h"
#include "MenuAdm.h"
void ocultar_senha(char senha[]) {
    int i = 0;
    char c;

    while (1) {
        c = getch();

        if (c == 13) {  // Se a tecla Enter for pressionada
            senha[i] = '\0';
            break;
        } else if (c == 8 && i > 0) {  // Se a tecla Backspace for pressionada
            printf("\b \b");  // Apaga o caractere da tela
            i--;
        } else if (c >= 32 && c <= 126) {  // Se o caractere for imprimível
            printf("*");
            senha[i] = c;
            i++;
        }
    }
}
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
    LoginAdminFile = fopen(".\\LoginAdm\\Login.txt", "r");
    SenhaAdminFile = fopen(".\\LoginAdm\\Senha.txt", "r");

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
            printf("Digite a senha: ");
            ocultar_senha(senha);
            printf("\n***********************************************\n");

            if (strcmp(login, loginAdmin) == 0 && strcmp(senha, senhaAdmin) == 0)
            {
                system("cls");
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
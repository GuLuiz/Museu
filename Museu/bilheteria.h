#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "MenuVisitante.h"

struct Bilhete
{
    char Name[20];
    char entrada[255];
    char email[255];
};
struct Bilhete Pessoas[100];
int indice = 0;
int cod;

void Cadastro();

FILE *arquivo;
FILE *code;

int bilheteria()
{
    char resposta;
    do
    {
        arquivo = fopen("Bilhete.txt", "r");
        code = fopen("CadastroCod.txt", "r");
        fscanf(code, "%d", &cod);

        int optionTheme = 0;
        int optionTicket = 0;
        system("cls");
        printf("\nNOME: ");
        fflush(stdin);
        fgets(Pessoas[indice].Name, sizeof(Pessoas[indice].Name), stdin);
        printf("\nEMAIL: ");
        fflush(stdin);
        fgets(Pessoas[indice].email, sizeof(Pessoas[indice].email), stdin);

        while (!(optionTicket == 1 || optionTicket == 2 || optionTicket == 3))
        {
            system("cls");
            printf("Qual entrada voce gostaria de comprar?? \n");
            printf("==============================================\n\n");

            printf("(1) - | %-20s | %-20s |\n", "Meia", "ValorX");
            printf("(2) - | %-20s | %-20s |\n", "Inteira", "ValorY");
            printf("(3) - | %-20s | %-20s |\n\n", "Isenta", "R$0");
            printf("==============================================\n");
            scanf("%d", &optionTicket);
        }
        // Use strcpy para atribuir uma string
        if (optionTicket == 1)
        {
            strcpy(Pessoas[indice].entrada, "Meia");
        }
        else if (optionTicket == 2)
        {
            strcpy(Pessoas[indice].entrada, "Inteira");
        }
        else if (optionTicket == 3)
        {
            strcpy(Pessoas[indice].entrada, "Isenta");
        }

        indice++;
        system("cls");
        arquivo = fopen("Bilhete.txt", "a");

        for (int i = 0; i < indice; i++)
        {
            fprintf(arquivo, "CÓDIGO DE CADASTRO : %d\n", cod);
            fprintf(arquivo, "====================================================\n");
            fprintf(arquivo, "NOME:%s\n", Pessoas[i].Name);
            fprintf(arquivo, "ENTRADA:%s\n", Pessoas[i].entrada);
            fprintf(arquivo, "EMAIL:%s\n", Pessoas[i].email);
            fprintf(arquivo, "====================================================\n");
        }

        fclose(arquivo); // Fecha o arquivo

        cod = cod + indice;
        code = fopen("CadastroCod.txt", "w");
        fprintf(code, "%d", cod);

        printf("Gerar outro bilhete? s/n\n");
        resposta = getchar();

    } while (resposta == "s" || resposta == "S");
    MenuVisitante();

}



#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

struct Bilhete
{
    int ID;
    char Name[20];
    char email[255];
    char entrada[255];
};

struct Bilhete Pessoas[100];
int indice = 0;
int cod;

FILE *arquivo;
FILE *code;

void bilheteria()
{
    arquivo = fopen("C:\\Museu\\Museu\\output\\bilhete.txt", "a");
    code = fopen("C:\\Museu\\Museu\\output\\CadastroCod.txt", "r");
    fscanf(code, "%d", &cod);

    int optionTicket = 0;
    system("cls");
    printf("==============================================\n");
    printf("             Cadastrando Bilhete \n");
    printf("==============================================\n");
    // validador caso haja caracteres vazias
    while (1)
    {
        printf("\nNOME: ");
        fflush(stdin);
        fgets(Pessoas[indice].Name, sizeof(Pessoas[indice].Name), stdin);
        if (strlen(Pessoas[indice].Name) > 0)
        {
            break; // Saia do loop se o nome não estiver vazio
        }
    }
    while (1)
    {
    printf("\nEMAIL: ");
    fflush(stdin);
    fgets(Pessoas[indice].email, sizeof(Pessoas[indice].email), stdin);
    
    if (strlen(Pessoas[indice].email) > 0)
        {
            break;
        }
    }
    

    while (!(optionTicket == 1 || optionTicket == 2 || optionTicket == 3))
    {
        system("cls");
        printf("Qual entrada você gostaria de comprar?? \n");
        printf("==============================================\n\n");

        printf("(1) - | %-20s | %-20s |\n", "Meia", "R$ 10,00");
        printf("(2) - | %-20s | %-20s |\n", "Inteira", "R$ 20,00");
        printf("(3) - | %-20s | %-20s |\n\n", "Isenta", "R$0");
        printf("==============================================\n");
        scanf("%d", &optionTicket);
    }

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

    Pessoas[indice].ID = cod;

    system("cls");
    printf("==============================================\n");
    printf("             Bilhete Cadastrado \n");
    printf("==============================================\n");
    printf("ID: %d\n", Pessoas[indice].ID);
    printf("NOME: %s", Pessoas[indice].Name);
    printf("ENTRADA: %s\n", Pessoas[indice].entrada);
    printf("EMAIL: %s\n", Pessoas[indice].email);
    printf("==============================================\n");
    indice++;

    fprintf(arquivo, "CÓDIGO DE CADASTRO : %d\n", cod);
    fprintf(arquivo, "====================================================\n");
    fprintf(arquivo, "NOME: %s", Pessoas[indice - 1].Name);
    fprintf(arquivo, "\nENTRADA: %s", Pessoas[indice - 1].entrada);
    fprintf(arquivo, "\nEMAIL: %s", Pessoas[indice - 1].email);
    fprintf(arquivo, "\n====================================================\n");

    fclose(arquivo);

    cod++;
    code = fopen("C:\\Museu\\Museu\\output\\CadastroCod.txt", "w");
    fprintf(code, "%d", cod);
    fclose(code);
}
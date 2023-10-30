#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
// Variaveis de escopo Global
struct Bilhete
{
    char Name[20];
    char ObraName[255];
    char entrada[255];
    char email[255];
};
struct Bilhete Pessoas[100];
int indice = 0;
int option;
int cod;

// declarando funções
void Cadastro();
void Print();

FILE *arquivo;
FILE *code;
// Código  Principal
int main()
{

    arquivo = fopen("Bilhete.txt", "r");
    code = fopen("CadastroCod.txt", "r");
    fscanf(code, "%d", &cod);
    do
    {
        option = 0;

        system("cls");
        printf("\n========================================\n");
        printf("               Bilheteria            \n");
        printf("========================================\n");
        printf("\n    ####### MENU #######\n\n");
        printf("( 1 ) CADASTRAR CONTATO \n");
        printf("( 2 ) iMPRIMIR CONTATOS \n");
        printf("( 3 ) SAIR \n");

        char input[10];
        scanf("%s", &input);



        // verificador valor de entrada
        if (isdigit(input[0]))
        {
            option = atoi(input);
            switch (option)
            {
            case 1:
                Cadastro();

                break;
            case 2:
                Print();
                break;
            default:
                printf("Numero incorreto");
                option = 0;
                Sleep(300);
                break;
            }
        }
        else
        {
            printf("Entrada invalida. Tente novamente.\n");
            Sleep(300);
        }

    } while (option != 3);

    cod = cod + indice;
    printf("o numero de user cadastrado é %d", cod);
    code = fopen("CadastroCod.txt", "w");
    fprintf(code, "%d", cod);

    return 0;
}

void Cadastro()
{

    int optionTheme = 0;
    int optionTicket = 0;
    system("cls");
    printf("\nNOME: ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(Pessoas[indice].Name, sizeof(Pessoas[indice].Name), stdin);
    printf("\nEMAIL: ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(Pessoas[indice].email, sizeof(Pessoas[indice].email), stdin);

    // Usuario vai escolher o Tema que ele deseja Ver
    while (optionTheme != 1 && optionTheme != 2 && optionTheme != 3)
    {
        system("cls");
        printf("%s, Seja bem vindo ao nosso Museu MultiTematico !!\n", Pessoas->Name);
        printf("==============================================\n");
        printf("qual tema voce gostaria de ver?\n\n");
        printf("(1) - tema1 \n");
        printf("(2) - tema2 \n");
        printf("(3) - tema3 \n\n");
        printf("Por favor escolhar apenas apenas um dos numeros : \n");
        scanf("%d", &optionTheme);
    }
    // Use strcpy para atribuir uma string
    if (optionTheme == 1)
    {
        strcpy(Pessoas[indice].ObraName, "tema 1");
    }
    else if (optionTheme == 2)
    {
        strcpy(Pessoas[indice].ObraName, "tema 2");
    }
    else if (optionTheme == 3)
    {
        strcpy(Pessoas[indice].ObraName, "tema 3");
    }

    // Usuario vai escolher qual entrada ele deseja Pagar
    while (optionTicket != 1 && optionTicket != 2 && optionTicket != 3)
    {
        system("cls");
        printf("Qual entrada voce gostaria de comprar?? \n");
        printf("==============================================\n\n");

        printf("(1) - | %-20s | %-20s |\n", "Meia", "ValorX");
        printf("(2) - | %-20s | %-20s |\n", "Inteira", "ValorY");
        printf("(3) - | %-20s | %-20s |\n\n", "Isenta", "R$0");
        Sleep(300);

        printf("Por favor escolhar apenas apenas um dos numeros : \n");
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

    // Reset de Valores

    optionTheme = 0;
    optionTicket = 0;
    indice++;
}

void Print()
{
    system("cls");
    arquivo = fopen("Bilhete.txt", "a");

    for (int i = 0; i < indice; i++)
    {
        fprintf(arquivo, "CÓDIGO DE CADASTRO : %d\n", cod);
        fprintf(arquivo, "====================================================\n");
        fprintf(arquivo, "NOME:%s\n", Pessoas[i].Name);
        fprintf(arquivo, "OBRA:%s\n", Pessoas[i].ObraName);
        fprintf(arquivo, "ENTRADA:%s\n", Pessoas[i].entrada);
        fprintf(arquivo, "EMAIL:%s\n", Pessoas[i].email);
        fprintf(arquivo, "====================================================\n");
    }

    fclose(arquivo); // Fecha o arquivo
    system("pause");
}
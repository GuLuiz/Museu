#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Quest.h"

void procurarID(int idDesejado)
{
    FILE *arquivo = fopen(".\\output\\bilhete.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de bilhetes.\n");
        return;
    }

    int encontrado = 0; // Flag para indicar se o dígito foi encontrado em algum ID

    char linha[255];
    int codigoLido;

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (sscanf(linha, "CÓDIGO DE CADASTRO : %d", &codigoLido) == 1)
        {
            if (codigoLido == idDesejado)
            {
                encontrado = 1;
                printf("Bilhete encontrado!\n\n");
                printf("%s", linha); // Imprime a linha com o código

                // Leia e imprima as linhas seguintes que contêm as informações do bilhete
                for (int i = 0; i < 4; i++)
                {
                    fgets(linha, sizeof(linha), arquivo);
                    printf("%s", linha);
                }
                break;
            }
        }
    }

    fclose(arquivo);

    if (encontrado)
    {
        printf("ID %d encontrado em algum ID.\n", idDesejado);
    }
    else
    {
        printf("ID %d não encontrado em nenhum ID.\n", idDesejado);
        return;
    }
}

void obras()
{
    FILE *Tesla;
    FILE *vangogh;
    FILE *Grito;
    FILE *Santos;
    int contadorTesla = 0;
    int contadorVan = 0;
    int contadorGrito = 0;
    int contadorSantos = 0;
    Tesla = fopen(".\\LoginAdm\\coutOBRAS\\tesla.txt", "r");
    vangogh = fopen(".\\LoginAdm\\coutOBRAS\\vangogh.txt", "r");
    Grito = fopen(".\\LoginAdm\\coutOBRAS\\grito.txt", "r");
    Santos = fopen(".\\LoginAdm\\coutOBRAS\\santosDumont.txt", "r");
    fscanf(Tesla, "%d", &contadorTesla);
    fscanf(Grito, "%d", &contadorGrito);
    fscanf(vangogh, "%d", &contadorVan);
    fscanf(Santos, "%d", &contadorSantos);
    fclose(Tesla);
    fclose(vangogh);
    fclose(Grito);
    fclose(Santos);

    int idDesejado;
    int codigo;
    FILE *arquivo2;
    int define;
    int sair = 0;
    char res;

    printf("Por favor, digite o ID conforme seu bilhete: ");
    scanf("%d", &idDesejado);
    procurarID(idDesejado);

    while (sair == 0)
    {
        printf("\nSeja bem vindo!\n");
        printf("===============================================\n");
        printf("                  OBRAS\n");
        printf("===============================================\n");
        printf("1 - Nikola Tesla\n");
        printf("2 - O grito\n");
        printf("3 - Santos Dumont\n");
        printf("4 - Van Gogh - 100 de arte moderna\n");
        printf("0 - Sair\n");
        printf("Escolha a obra desejada: ");
        scanf("%d", &define);

        switch (define)
        {
        case 0:
            printf("Saindo...\n");
            sair = 1;
            break;

        case 1:
            system("start ..\\Obras\\NikolaTesla.png");

            printf("Gostaria de responder nosso questionário relacionado à obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 1);
            }
            contadorTesla += 1;
            break;

        case 2:
            system("start ..\\Obras\\OGrito.png");
            printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 2);
            }
            contadorGrito += 1;
            break;

        case 3:
            system("start ..\\Obras\\SantosDumont.png");
            printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 3);
            }
            contadorSantos += 1;
            break;

        case 4:
            system("start ..\\Obras\\VanGogh.png");
            printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 4);
            }
            contadorVan += 1;
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
        Tesla = fopen(".\\output\\tesla.txt", "w");
        vangogh = fopen(".\\output\\vangogh.txt", "w");
        Grito = fopen(".\\output\\grito.txt", "w");
        Santos = fopen(".\\output\\santosDumont.txt", "w");
        fprintf(Tesla, "%d", contadorTesla);
        fprintf(Grito, "%d", contadorGrito);
        fprintf(vangogh, "%d", contadorVan);
        fprintf(Santos, "%d", contadorSantos);
        fclose(Tesla);
        fclose(vangogh);
        fclose(Grito);
        fclose(Santos);
    }

    system("cls");
    printf("\n**************************************\n");
    printf("*   MUITO OBRIGADO POR VISITAR      *\n");
    printf("*           NOSSO MUSEU!            *\n");
    printf("**************************************\n");
}

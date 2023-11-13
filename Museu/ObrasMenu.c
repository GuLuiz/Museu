#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Quest.h"
#include <stdbool.h>

void removeNewline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0'; // Substitui o '\n' por '\0'
    }
}

bool contemDigito(int numero, int digito)
{
    char strNumero[20];
    sprintf(strNumero, "%d", numero);

    for (size_t i = 0; i < strlen(strNumero); i++)
    {
        if (strNumero[i] - '0' == digito)
        {
            return true;
        }
    }
    return false;
}

void obras()
{
    int idDesejado;
    int codigo;
    FILE *arquivo2;
    int define;
    int sair = 0;

    printf("Por favor, digite o ID conforme seu bilhete: ");
    scanf("%d", &idDesejado);

    arquivo2 = fopen("C:\\Museu\\Museu\\output\\Bilhete.txt", "r");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo de bilhetes.\n");
        return;
    }

    int encontrado = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo2) != NULL)
    {
        removeNewline(linha);

        if (sscanf(linha, "CÓDIGO DE CADASTRO : %d", &codigo) == 1 ||
            sscanf(linha, "CÓDIGO DE CADASTRO :%d", &codigo) == 1)
        {
            if (contemDigito(codigo, idDesejado))
            {
                encontrado = 1;
                break;
            }
        }
    }

    fclose(arquivo2);

    if (encontrado)
    {
        printf("Dígito %d encontrado em algum ID.\n", idDesejado);
    }
    else
    {
        printf("Dígito %d não encontrado em nenhum ID.\n", idDesejado);
        return; // Se não encontrar o ID, não faz sentido continuar
    }

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
        char res;

        switch (define)
        {
        case 0:
            printf("Saindo...\n");
            sair = 1;
            break;

        case 1:
            system("start C:\\Museu\\Obras\\NikolaTesla.png");

            printf("Gostaria de responder nosso questionário relacionado à obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 1);
            }
            break;

        case 2:
            system("start C:\\Museu\\Obras\\OGrito.png");
            printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 2);
            }
            break;

        case 3:
            system("start C:\\Museu\\Obras\\SantosDumont.png");
            printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 3);
            }
            break;

        case 4:
            system("start C:\\Museu\\Obras\\VanGogh.png");
            printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
            scanf(" %c", &res);
            if (res == 's')
            {
                questionarios(idDesejado, 4);
            }
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Quest.h"

void obras()
{
    char NomeValidado[100];
    int found = 0;
    FILE *arquivo2;
    int define;
    int sair = 0;

    printf("Por favor, digite seu Nome para prosseguirmos: ");
    scanf(" %s", NomeValidado);

    arquivo2 = fopen("C:\\Museu\\Museu\\output\\Bilhete.txt", "r");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo de bilhetes.\n");
        return;
    }

    char pesquisa[100];

    while (fgets(pesquisa, 100, arquivo2) != NULL) {
        strtok(pesquisa, "\n");
        if (strstr(pesquisa, NomeValidado) != NULL) {
            printf("OK, seu nome está cadastrado no nosso Sistema!\n");
            found = 1;
            system("pause");
            while (sair == 0)
            {
                system("cls");
                printf("Seja bem vindo, %s!", NomeValidado);
                Sleep(500);
                printf("\n===============================================");
                printf("\n                  OBRAS");
                printf("\n===============================================\n");
                printf("\n1 - Nikola Tesla");
                printf("\n2 - O grito");
                printf("\n3 - Santos Dumont");
                printf("\n4 - Van Gogh - 100 de arte moderna");
                printf("\n0 - Sair");
                printf("\nEscolha a obra desejada: ");
                scanf("%d", &define);
                char res;
                switch (define)
                {
                case 1:
                    system("start C:\\Museu\\Obras\\NikolaTesla.png");

                    printf("Gostaria de responder nosso questionário relacionado à obra? (s/n)");
                    scanf(" %c", &res);
                    if (res == 's')
                    {
                        questionario(1, NomeValidado);
                        break;
                    }
                    else
                    {
                        break;
                    }

                case 2:

                    system("start C:\\Museu\\Obras\\OGrito.png");
                    printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
                    scanf(" %c", &res);
                    if (res == 's')
                    {
                        questionario(2, NomeValidado);
                        break;
                    }
                    else
                    {
                        break;
                    }
                    break;
                case 3:

                    system("start C:\\Museu\\Obras\\SantosDumont.png");
                    printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
                    scanf(" %c", &res);
                    if (res == 's')
                    {
                        questionario(3, NomeValidado);
                        break;
                    }
                    else
                    {
                        break;
                    }
                    break;
                case 4:

                    system("start C:\\Museu\\Obras\\VanGogh.png");
                    printf("Gostaria de responder nosso questionário relacionado a obra? (s/n)");
                    scanf(" %c", &res);
                    if (res == 's')
                    {
                        questionario(4, NomeValidado);
                        break;
                    }
                    else
                    {
                        break;
                    }
                    break;

                case 0:
                    printf("Saindo...");
                    sair++;
                    break;
                }
            }
        }
    }
    if (found != 1)
    {
        printf("Nome nao cadastrado !");
        Sleep(500);
    }
    fclose(arquivo2);
}

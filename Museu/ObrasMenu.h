#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *arquivo2; 
void obras()
{
    char pesquisa[100];
    char NomeValidado[100];
    int found = 0;
    arquivo2 = fopen("Bilhete.txt", "r");
    int define;
    int sair = 0;

    printf("Por favor, digite seu Nome para prosseguimos :");
    fflush(stdin);
    fgets(NomeValidado, 100, stdin);

    while (fgets(pesquisa, 100, arquivo2) != NULL)
    {
        if (strstr(pesquisa, NomeValidado) != NULL)
        {
            printf("OK, seu nome esta Cadastrado no nosso Sistema! \n");
            found = 1;
            system("pause");
            system("cls");
            printf("Seja bem vindo, %s!",NomeValidado);
            Sleep(500);
            printf("\n===============================================");
            printf("\n                  OBRAS");
            printf("\n===============================================\n");
            printf("\n1 - Nikola Tesla");
            printf("\n2 - O grito");
            printf("\n3 - Santos Dumont");
            printf("\n4 - 100 anos da arte moderna");
            printf("\n0 - Sair");
            printf("Escolha a obra desejada: ");
            scanf("%d", &define);
            switch (define)
                while (sair == 0)
                {
                    {
                    case 1:
                        system("start C:\\Museu\\Obras\\NikolaTesla.png");
                        break;
                    case 2:
                        system("start C:\\Museu\\Obras\\OGrito.png");
                        break;
                    case 3:
                        system("start C:\\Museu\\Obras\\SantosDumont.png");
                        break;
                    case 4:
                        system("start C:\\Museu\\Obras\\VanGogh.png");
                        break;

                    default:
                        printf("Número de obra inválida!");
                        sair++;
                        break;
                    }
                }
        }
        
    }
    if(found != 1){
            printf("Nome nao cadastrado !");
            Sleep(500);
        }
    fclose(arquivo2);
}

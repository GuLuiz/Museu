#include <stdio.h>

int obrasAdm()
{

    int define;
    int sair = 0;
    
    while (sair == 0){
    system("cls");
    printf("\n***********************************************");
    printf("\n                  OBRAS");
    printf("\n***********************************************\n");
    printf("\n1 - Nikola Tesla");
    printf("\n2 - O grito");
    printf("\n3 - Santos Dumont");
    printf("\n4 - 100 anos da arte mordena");
    printf("\n0 - Sair");
    printf("\nEscolha a obra desejada: ");
    scanf("%d", &define);
    switch (define)
        {
            case 0:
                return 0;
                break;
            case 1:
                system("start D:\\C\\Obras\\NikolaTesla.png");
                break;
            case 2:
                system("start D:\\C\\Obras\\OGrito.png");
                break;
            case 3:
                system("start D:\\C\\Obras\\SantosDumont.png");
                break;
            case 4:
                system("start D:\\C\\Obras\\VanGogh.png");
                break;

            default:
                printf("Número de obra inválida!");
                break;
            }
        }
}
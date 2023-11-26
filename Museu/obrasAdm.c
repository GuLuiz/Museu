#include <stdio.h>
#include <Windows.h>

int obrasAdm()
{
    int define;
    int sair = 0;

    while (sair == 0)
    {
        system("cls");
        printf("\n***********************************************");
        printf("\n                  OBRAS");
        printf("\n***********************************************\n");
        printf("\n1 - Nikola Tesla");
        printf("\n2 - O grito");
        printf("\n3 - Santos Dumont");
        printf("\n4 - 100 anos da arte moderna");
        printf("\n0 - Sair");
        printf("\nEscolha a obra desejada: ");
        scanf("%d", &define);

        switch (define)
        {
        case 0:
            sair++;
            return 1; // Retorna 0 quando o usuário escolhe sair
            break;

        case 1:
            system("start ..\\Obras\\NikolaTesla.png");
            break;
        case 2:
            system("start ..\\Obras\\OGrito.png");
            break;
        case 3:
            system("start ..\\Obras\\SantosDumont.png");
            break;
        case 4:
            system("start ..\\Obras\\VanGogh.png");
            break;

        default:
            printf("Número de obra inválida!");
            break;
        }
    }
}
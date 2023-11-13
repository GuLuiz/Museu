#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "bilheteria.h"
#include "ObrasMenu.h"

int MenuVisitante()
{
    char resposta;
    do
    {
        bilheteria();
        printf("Deseja realizar outro Cadastro? (s/n)");
        scanf(" %c", &resposta);

    } while (resposta == 's' || resposta == 'S');
    
    obras();
    return 0;
}
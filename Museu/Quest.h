#include <stdio.h>


void questionario(int obra)
{
    FILE *file = fopen("ObraAcessada.txt", "r");
// Encontrar qual obra foi acessada e contar quantidade de visitas
    int CountTesla = 0;
    int CountGrito = 0;
    int CountDumont = 0;
    int CountGogh = 0;
    fscanf(file, "%d %d %d %d", &CountTesla, &CountGrito, &CountDumont, &CountGogh);
    fclose(file);

    if(obra = 1){
        CountTesla++;
    }else if (obra = 2)
    {
        CountGrito++;
    }else if (obra = 3)
    {
        CountDumont++;
    }else if (obra = 4)
    {
        CountGogh++;
    }
    int cod;

    file = fopen("ObraAcessada.txt", "w");
        fprintf(file, "%d %d %d %d", CountTesla, CountGrito, CountDumont, CountGogh);
        fclose(file);

    //
    
}
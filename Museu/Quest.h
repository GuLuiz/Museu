#include <stdio.h>


void questionario(int obra,char Nome)
{
    char Username = nome;
    FILE *CountObras = fopen("ObraAcessada.txt", "r");
    FILE *QuestTesla = fopen("C:\\Museu\\Obras\\Tesla.txt", "r");
    FILE *QuestGrito = fopen("C:\\Museu\\Obras\\Grito.txt", "r");
    FILE *QuestDumont = fopen("C:\\Museu\\Obras\\Dumont.txt", "r");
    FILE *QuestGogh = fopen("C:\\Museu\\Obras\\Gogh.txt", "r");
// Encontrar qual obra foi acessada e contar quantidade de visitas
    int CountTesla = 0;
    int CountGrito = 0;
    int CountDumont = 0;
    int CountGogh = 0;
    fscanf(file, "%d %d %d %d", &CountTesla, &CountGrito, &CountDumont, &CountGogh);
    fclose(file);

    if(obra = 1)
    {
        int nota;
        QuestTesla = fopen("C:\\Museu\\ObrasTxT\\Tesla.txt", "w");
        printf("Qual nota de 0 a 10 você daria para esta obra?");
        scanf("%d", &nota);
        CountTesla++;
    }else if (obra = 2)
    {
        int nota;
        QuestGrito = fopen("C:\\Museu\\Obras\\Grito.txt", "a");
        printf("Qual nota de 0 a 10 você daria para esta obra?");
        scanf("%d", &nota);
        CountGrito++;
    }else if (obra = 3)
    {
        int nota;
        QuestDumont = fopen("C:\\Museu\\Obras\\Dumont.txt", "a");
        printf("Qual nota de 0 a 10 você daria para esta obra?");
        scanf("%d", &nota);
        CountDumont++;
    }else if (obra = 4)
    {
        int nota;
        QuestGogh = fopen("C:\\Museu\\Obras\\Gogh.txt", "a");
        printf("Qual nota de 0 a 10 você daria para esta obra?");
        scanf("%d", &nota);
        CountGogh++;
    }
    int cod;

    CountObras = fopen("ObraAcessada.txt", "w");
    fprintf(file, "%d %d %d %d\n", CountTesla, CountGrito, CountDumont, CountGogh);
    fclose(file);

    //
    
    
}
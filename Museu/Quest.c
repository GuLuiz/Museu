#include <stdio.h>
#include <string.h>

void questionario(int obra, char Nome[])
{
        int nota;
        int importancia;
        int info;
        int sast;
        int notaN;
        int importanciaN;
        int infoN;
        int sastN;
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
    CountObras = fopen("ObraAcessada.txt", "r");
    fscanf(CountObras, "%d %d %d %d", &CountTesla, &CountGrito, &CountDumont, &CountGogh);
    fclose(CountObras);

    if (obra == 1)
    {
        QuestTesla = fopen("C:\\Museu\\ObrasTxT\\Tesla.txt", "r");
        fscanf(QuestTesla, "%d %d %d %d", &nota, &importancia, &info, &sast);
        fclose(QuestTesla);
        int notaN;
        int importanciaN;
        int infoN;
        int sastN;
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &notaN);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &importanciaN);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &infoN);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao? %s", Nome);
        scanf("%d", &sastN);

        nota = nota + notaN;
        importancia = importancia + notaN;
        info = info + infoN;
        sast = sast + sastN;

        QuestTesla = fopen("C:\\Museu\\ObrasTxT\\Tesla.txt", "w");
        fprintf(QuestTesla, "%d %d %d %d\n", nota, importancia, info, sast);
        fclose(QuestTesla);

        CountTesla++;
    }
    else if (obra == 2)
    {
        QuestGrito = fopen("C:\\Museu\\Obras\\Grito.txt", "r");
        fscanf(QuestGrito, "%d %d %d %d", &nota, &importancia, &info, &sast);
        fclose(QuestGrito);
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &notaN);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &importanciaN);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &infoN);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao?");
        scanf("%d", &sastN);

        nota = nota + notaN;
        importancia = importancia + notaN;
        info = info + infoN;
        sast = sast + sastN;

        QuestGrito = fopen("C:\\Museu\\ObrasTxT\\Grito.txt", "w");
        fprintf(QuestGrito, "%d %d %d %d\n", nota, importancia, info, sast);
        fclose(QuestGrito);
        CountGrito++;
    }
    else if (obra == 3)
    {
        QuestDumont = fopen("C:\\Museu\\Obras\\Dumont.txt", "r");
        fscanf(QuestDumont, "%d %d %d %d", &nota, &importancia, &info, &sast);
        fclose(QuestDumont);
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &notaN);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &importanciaN);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &infoN);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao?");
        scanf("%d", &sastN);

        nota = nota + notaN;
        importancia = importancia + notaN;
        info = info + infoN;
        sast = sast + sastN;

        QuestDumont = fopen("C:\\Museu\\ObrasTxT\\Dumont.txt", "w");
        fprintf(QuestDumont, "%d %d %d %d\n", nota, importancia, info, sast);
        fclose(QuestDumont);
        CountDumont++;
    }
    else if (obra == 4)
    {
        QuestGogh = fopen("C:\\Museu\\Obras\\Gogh.txt", "r");
        fscanf(QuestGogh, "%d %d %d %d", &nota, &importancia, &info, &sast);
        fclose(QuestGogh);
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &notaN);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &importanciaN);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &infoN);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao?");
        scanf("%d", &sastN);

        nota = nota + notaN;
        importancia = importancia + notaN;
        info = info + infoN;
        sast = sast + sastN;

        QuestGogh = fopen("C:\\Museu\\ObrasTxT\\Gogh.txt", "w");
        fprintf(QuestGogh, "%d %d %d %d\n", nota, importancia, info, sast);
        fclose(QuestGogh);
        CountGogh++;
    }

    CountObras = fopen("ObraAcessada.txt", "w");
    fprintf(CountObras, "%d %d %d %d", CountTesla, CountGrito, CountDumont, CountGogh);
    fclose(CountObras);

    //
}
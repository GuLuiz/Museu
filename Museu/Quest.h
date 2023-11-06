#include <stdio.h>

void questionario(int obra, char Nome)
{
    char Username = Nome;
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
    fscanf(CountObras, "%d", &CountTesla);
    fscanf(QuestTesla, "%d", &CountGrito);
    fscanf(QuestGrito, "%d", &CountDumont);
    fscanf(QuestDumont, "%d", &CountGogh);
    fscanf(QuestGogh, "%d", &CountGogh);
    fclose(CountObras);
    fclose(QuestTesla);
    fclose(QuestGrito);
    fclose(QuestDumont);
    fclose(QuestGogh);

    if (obra == 1)
    {
        QuestTesla = fopen("C:\\Museu\\ObrasTxT\\Tesla.txt", "r");
        int nota;
        int importancia;
        int info;
        int sast;
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
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao?");
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
        int nota;
        int importancia;
        int info;
        int sast;
        fscanf(QuestGrito, "%d %d %d %d", &nota, &importancia, &info, &sast);
        fclose(QuestGrito);
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
        int nota;
        int importancia;
        int info;
        int sast;
        fscanf(QuestDumont, "%d %d %d %d", &nota, &importancia, &info, &sast);
        fclose(QuestDumont);
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
        int nota;
        int importancia;
        int info;
        int sast;
        fscanf(QuestGogh, "%d %d %d %d", &nota, &importancia, &info, &sast);
        fclose(QuestGogh);
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
    int cod;

    CountObras = fopen("ObraAcessada.txt", "w");
    fprintf(CountObras, "%d", &CountTesla);
    fprintf(QuestTesla, "%d", &CountGrito);
    fprintf(QuestGrito, "%d", &CountDumont);
    fprintf(QuestDumont, "%d", &CountGogh);
    fprintf(QuestGogh, "%d", &CountGogh);
    fclose(CountObras);
    fclose(QuestTesla);
    fclose(QuestGrito);
    fclose(QuestDumont);
    fclose(QuestGogh);

    //
}
#include <stdio.h>
#include <string.h>
#include "ObrasMenu.h"

struct Obra
{
    int ID;
    int notaObra;
    int importanciaObra;
    int informativoObra;
    int satisfacaoObra;
};

void questionarios(int id, int obras)
{

    FILE *questionario;
    struct Obra obra;

    obra.ID = id;
    switch (obras)
    {
    case 1:
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &obra.notaObra);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &obra.importanciaObra);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &obra.informativoObra);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao? %s");
        scanf("%d", &obra.satisfacaoObra);
        questionario = fopen("C:\\Museu\\Museu\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: Nikola Tesla \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    case 2:
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &obra.notaObra);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &obra.importanciaObra);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &obra.informativoObra);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao? %s");
        scanf("%d", &obra.satisfacaoObra);
        questionario = fopen("C:\\Museu\\Museu\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: O Grito \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    case 3:
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &obra.notaObra);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &obra.importanciaObra);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &obra.informativoObra);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao? %s");
        scanf("%d", &obra.satisfacaoObra);
        questionario = fopen("C:\\Museu\\Museu\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: Santos Dumont \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    case 4:
        printf("de uma escala de 0 a 10,qual nota você daria para esta obra?");
        scanf("%d", &obra.notaObra);
        printf("de uma escala de 0 a 10,como voce avalia a importancia desta obra?");
        scanf("%d", &obra.importanciaObra);
        printf("de uma escala de 0 a 10, o quao informativa voce achou essa exposicao?");
        scanf("%d", &obra.informativoObra);
        printf("de uma escala de 0 a 10, o quao sastifeito voce ficou com essa exposicao? %s");
        scanf("%d", &obra.satisfacaoObra);
        questionario = fopen("C:\\Museu\\Museu\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: Van Gogh - 100 de arte moderna \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    default:
        break;
    }
}
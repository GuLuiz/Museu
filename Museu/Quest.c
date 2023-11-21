#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        do
        {
            printf("Em uma escala de 0 a 10, qual nota você daria para esta obra? ");
            scanf("%d", &obra.notaObra);
        } while (obra.notaObra < 0 || obra.notaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, como você avalia a importância desta obra? ");
            scanf("%d", &obra.importanciaObra);
        } while (obra.importanciaObra < 0 || obra.importanciaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão informativa você achou essa exposição? ");
            scanf("%d", &obra.informativoObra);
        } while (obra.informativoObra < 0 || obra.informativoObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão satisfeito você ficou com essa exposição? ");
            scanf("%d", &obra.satisfacaoObra);
        } while (obra.satisfacaoObra < 0 || obra.satisfacaoObra > 10);

        questionario = fopen(".\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: Nikola Tesla \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    case 2:
        do
        {
            printf("Em uma escala de 0 a 10, qual nota você daria para esta obra? ");
            scanf("%d", &obra.notaObra);
        } while (obra.notaObra < 0 || obra.notaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, como você avalia a importância desta obra? ");
            scanf("%d", &obra.importanciaObra);
        } while (obra.importanciaObra < 0 || obra.importanciaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão informativa você achou essa exposição? ");
            scanf("%d", &obra.informativoObra);
        } while (obra.informativoObra < 0 || obra.informativoObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão satisfeito você ficou com essa exposição? ");
            scanf("%d", &obra.satisfacaoObra);
        } while (obra.satisfacaoObra < 0 || obra.satisfacaoObra > 10);

        questionario = fopen(".\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: O Grito \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    case 3:
        do
        {
            printf("Em uma escala de 0 a 10, qual nota você daria para esta obra? ");
            scanf("%d", &obra.notaObra);
        } while (obra.notaObra < 0 || obra.notaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, como você avalia a importância desta obra? ");
            scanf("%d", &obra.importanciaObra);
        } while (obra.importanciaObra < 0 || obra.importanciaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão informativa você achou essa exposição? ");
            scanf("%d", &obra.informativoObra);
        } while (obra.informativoObra < 0 || obra.informativoObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão satisfeito você ficou com essa exposição? ");
            scanf("%d", &obra.satisfacaoObra);
        } while (obra.satisfacaoObra < 0 || obra.satisfacaoObra > 10);

        questionario = fopen(".\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: Santos Dumont \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    case 4:
        do
        {
            printf("Em uma escala de 0 a 10, qual nota você daria para esta obra? ");
            scanf("%d", &obra.notaObra);
        } while (obra.notaObra < 0 || obra.notaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, como você avalia a importância desta obra? ");
            scanf("%d", &obra.importanciaObra);
        } while (obra.importanciaObra < 0 || obra.importanciaObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão informativa você achou essa exposição? ");
            scanf("%d", &obra.informativoObra);
        } while (obra.informativoObra < 0 || obra.informativoObra > 10);

        do
        {
            printf("Em uma escala de 0 a 10, o quão satisfeito você ficou com essa exposição? ");
            scanf("%d", &obra.satisfacaoObra);
        } while (obra.satisfacaoObra < 0 || obra.satisfacaoObra > 10);

        questionario = fopen(".\\output\\Questionario.txt", "a");
        fprintf(questionario, "\nUsuario: %d \n Obra: Van Gogh - 100 de arte moderna \n Notas: %d %d %d %d", obra.ID, obra.notaObra, obra.importanciaObra, obra.informativoObra, obra.satisfacaoObra);
        fclose(questionario);
        break;
    default:
        break;
    }

    system("cls");
    printf("\n**************************************\n");
    printf("*   MUITO OBRIGADO POR VISITAR      *\n");
    printf("*           NOSSO MUSEU!            *\n");
    printf("**************************************\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Relatorio.h"

#define MAX_OBRAS 100
#define MAX_USUARIOS 100

typedef struct
{
    int usuario;
    char obra[100];
    int notas[4];
} RespostaUsuario;

typedef struct
{
    char obra[100];
    double media_notas[4];
    int contador;
} RelatorioObra;

double calcularMedia(int notas[], int tamanho)
{
    if (tamanho == 0)
        return 0;

    int soma = 0;
    for (int i = 0; i < tamanho; ++i)
    {
        soma += notas[i];
    }

    return (double)soma / tamanho;
}

int Relatorio()
{
    RespostaUsuario respostas[MAX_USUARIOS];
    RelatorioObra relatorios[MAX_OBRAS];

    FILE *arquivoEntrada = fopen(".\\output\\Questionario.txt", "r");
    if (arquivoEntrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    int numRespostas = 0;
    while (fscanf(arquivoEntrada, " Usuario: %d\n Obra: %[^\n]\n Notas: %d %d %d %d\n",
                  &respostas[numRespostas].usuario,
                  respostas[numRespostas].obra,
                  &respostas[numRespostas].notas[0],
                  &respostas[numRespostas].notas[1],
                  &respostas[numRespostas].notas[2],
                  &respostas[numRespostas].notas[3]) == 6)
    {
        numRespostas++;
    }

    fclose(arquivoEntrada);

    int numRelatorios = 0;
    int obraMaisAcessadaIndex = 0;
    int obraMenosAcessadaIndex = 0;

    for (int i = 0; i < numRespostas; ++i)
    {
        int obraEncontrada = 0;
        for (int j = 0; j < numRelatorios; ++j)
        {
            if (strcmp(relatorios[j].obra, respostas[i].obra) == 0)
            {
                for (int k = 0; k < 4; ++k)
                {
                    relatorios[j].media_notas[k] += respostas[i].notas[k];
                }
                relatorios[j].contador++;
                obraEncontrada = 1;
                break;
            }
        }

        if (!obraEncontrada)
        {
            strcpy(relatorios[numRelatorios].obra, respostas[i].obra);
            for (int k = 0; k < 4; ++k)
            {
                relatorios[numRelatorios].media_notas[k] = respostas[i].notas[k];
            }
            relatorios[numRelatorios].contador = 1;
            numRelatorios++;

            // Encontra a obra mais acessada e a menos acessada
            if (relatorios[numRelatorios - 1].contador > relatorios[obraMaisAcessadaIndex].contador)
                obraMaisAcessadaIndex = numRelatorios - 1;
            if (relatorios[numRelatorios - 1].contador < relatorios[obraMenosAcessadaIndex].contador)
                obraMenosAcessadaIndex = numRelatorios - 1;
        }
    }

    FILE *arquivoSaida = fopen(".\\output\\relatorio.txt", "w");
    if (arquivoSaida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }
    fprintf(arquivoSaida, "===========================================================\n");
    fprintf(arquivoSaida, "                     Relatório Geral\n");
    fprintf(arquivoSaida, "===========================================================\n");
    fprintf(arquivoSaida, "Obra com Maior Valor: %s (Valor: %d)\n", obraMaiorNome, maiorValor);
    fprintf(arquivoSaida, "Obra com Menor Valor: %s (Valor: %d)\n", obraMenorNome, menorValor);
    fprintf(arquivoSaida, "===========================================================\n\n");


    for (int i = 0; i < numRelatorios; ++i)
    {

        char Perguntas[4][50];
        strcpy(Perguntas[0], "| Nota        |");
        strcpy(Perguntas[1], "| importancia |");
        strcpy(Perguntas[2], "| informativa |");
        strcpy(Perguntas[3], "| sastifação  |");

        fprintf(arquivoSaida, "===========================================================\n");
        fprintf(arquivoSaida, "  Relatório da obra %-30s  \n", relatorios[i].obra);
        fprintf(arquivoSaida, "===========================================================\n");

        for (int j = 0; j < 4; ++j)
        {
            double media = relatorios[i].media_notas[j] / relatorios[i].contador;
            fprintf(arquivoSaida, "%s Média Avaliativa: %-6.2f |\n", Perguntas[j], media);
        }

        fprintf(arquivoSaida, "===========================================================\n\n");
    }
    fclose(arquivoSaida);

    return 0;
}
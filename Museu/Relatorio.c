#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBRAS 100
#define MAX_USUARIOS 100

typedef struct {
    int usuario;
    char obra[100];
    int notas[4];
} RespostaUsuario;

typedef struct {
    char obra[100];
    double media_notas[4];
    int contador;
} RelatorioObra;

double calcularMedia(int notas[], int tamanho) {
    if (tamanho == 0) return 0;

    int soma = 0;
    for (int i = 0; i < tamanho; ++i) {
        soma += notas[i];
    }

    return (double)soma / tamanho;
}

int Relatorio() {
    RespostaUsuario respostas[MAX_USUARIOS];
    RelatorioObra relatorios[MAX_OBRAS];

    FILE *arquivoEntrada = fopen("C:\\Museu\\Museu\\output\\Questionario.txt", "r");
    if (arquivoEntrada == NULL) {
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
                  &respostas[numRespostas].notas[3]) == 6) {
        numRespostas++;
    }

    fclose(arquivoEntrada);

    int numRelatorios = 0;
    for (int i = 0; i < numRespostas; ++i) {
        int obraEncontrada = 0;
        for (int j = 0; j < numRelatorios; ++j) {
            if (strcmp(relatorios[j].obra, respostas[i].obra) == 0) {
                for (int k = 0; k < 4; ++k) {
                    relatorios[j].media_notas[k] += respostas[i].notas[k];
                }
                relatorios[j].contador++;
                obraEncontrada = 1;
                break;
            }
        }

        if (!obraEncontrada) {
            strcpy(relatorios[numRelatorios].obra, respostas[i].obra);
            for (int k = 0; k < 4; ++k) {
                relatorios[numRelatorios].media_notas[k] = respostas[i].notas[k];
            }
            relatorios[numRelatorios].contador = 1;
            numRelatorios++;
        }
    }

    FILE *arquivoSaida = fopen("C:\\Museu\\Museu\\output\\relatorio.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    for (int i = 0; i < numRelatorios; ++i) {
        fprintf(arquivoSaida, "Relatório para a obra '%s':\n", relatorios[i].obra);
        for (int j = 0; j < 4; ++j) {
            double media = relatorios[i].media_notas[j] / relatorios[i].contador;
            fprintf(arquivoSaida, "Média da pergunta %d: %.2f\n", j + 1, media);
        }
        fprintf(arquivoSaida, "\n");
    }

    fclose(arquivoSaida);

    return 0;
}
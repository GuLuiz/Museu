#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criarBackup(const char *origem, const char *destino)
{
    FILE *origemArquivo = fopen(origem, "r");
    FILE *destinoArquivo = fopen(destino, "w");

    if (origemArquivo == NULL || destinoArquivo == NULL)
    {
        printf("Erro ao abrir os arquivos para backup.\n");
        return;
    }
    time_t tempoAtual;
    time(&tempoAtual);
    struct tm *infoTempo = localtime(&tempoAtual);

    char nomeBackup[100];
    fprintf(destinoArquivo, "Backup gerado em %02d/%02d/%02d %02d:%02d\n\n",
            infoTempo->tm_mday, infoTempo->tm_mon + 1, infoTempo->tm_year % 100,
            infoTempo->tm_hour, infoTempo->tm_min);

    char linha[1000];

    while (fgets(linha, sizeof(linha), origemArquivo) != NULL)
    {
        fputs(linha, destinoArquivo);
    }

    fclose(origemArquivo);
    fclose(destinoArquivo);

    printf("Backup criado com sucesso!\n");
}

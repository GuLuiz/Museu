#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int maiorValor, menorValor;
char obraMaiorNome[50], obraMenorNome[50];

void obterNomeObra(int valor, char nomeObra[])
{
    const char *nomes[] = {"Tesla", "Van Gogh", "O Grito", "Santos Dumont", "Desconhecido"};
    if (valor >= 0 && valor <= 3)
    {
        strcpy(nomeObra, nomes[valor]);
    }
    else
    {
        strcpy(nomeObra, nomes[4]);
    }
}

void encontrarMaiorMenorValor(int valores[], int *maior, int *menor, char *nomeMaior, char *nomeMenor)
{
    int tempMaiorValor = valores[0];
    int tempObraMaiorValor = 0;

    int tempMenorValor = valores[0];
    int tempObraMenorValor = 0;

    for (int i = 1; i < 4; ++i)
    {
        if (valores[i] > tempMaiorValor)
        {
            tempMaiorValor = valores[i];
            tempObraMaiorValor = i;
        }

        if (valores[i] < tempMenorValor)
        {
            tempMenorValor = valores[i];
            tempObraMenorValor = i;
        }
    }

    obterNomeObra(tempObraMaiorValor, nomeMaior);
    obterNomeObra(tempObraMenorValor, nomeMenor);

    *maior = tempMaiorValor;
    *menor = tempMenorValor;
}

int calcObras(int *maiorValor, int *menorValor, char *obraMaiornome, char *obraMenornome)
{
    int contadorObras[4] = {0}; // Índice 0: Tesla, 1: Van Gogh, 2: O Grito, 3: Santos Dumont

    FILE *arquivos[4];
    const char *nomesArquivos[] = {".\\output\\tesla.txt", ".\\output\\vangogh.txt", ".\\output\\grito.txt", ".\\output\\santosDumont.txt"};

    for (int i = 0; i < 4; ++i)
    {
        arquivos[i] = fopen(nomesArquivos[i], "r");
        if (arquivos[i] == NULL)
        {
            printf("Erro ao abrir um dos arquivos de contagem de obras.\n");
            return 1;
        }

        fscanf(arquivos[i], "%d", &contadorObras[i]);

        fclose(arquivos[i]);
    }

    encontrarMaiorMenorValor(contadorObras, maiorValor, menorValor, obraMaiornome, obraMenornome);

    return 0;
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
    calcObras(&maiorValor, &menorValor, obraMaiorNome, obraMenorNome);

    system("start .\\output\\relatorio.txt");
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
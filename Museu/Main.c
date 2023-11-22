
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "Login.h"
#include <stdio.h>

int maiorValor, menorValor;
char obraMaiorNome[50], obraMenorNome[50];
void obterNomeObra(int valor, char nomeObra[]) {
    if (valor == 0) {
        strcpy(nomeObra, "Tesla");
    } else if (valor == 1) {
        strcpy(nomeObra, "Van Gogh");
    } else if (valor == 2) {
        strcpy(nomeObra, "O Grito");
    } else if (valor == 3) {
        strcpy(nomeObra, "Santos Dumont");
    } else {
        strcpy(nomeObra, "Desconhecido");
    }
}
int calcObras(int *maiorValor, int *menorValor, char *obraMaiornome, char *obraMenornome);



int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    
    SetConsoleOutputCP(CPAGE_UTF8);

    calcObras(&maiorValor, &menorValor, obraMaiorNome, obraMenorNome);
    
    Login();

    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}


int calcObras(int *maiorValor, int *menorValor, char *obraMaiornome, char *obraMenornome) {
    int contadorTesla = 0;
    int contadorVan = 0;
    int contadorGrito = 0;
    int contadorSantos = 0;

    FILE *Tesla;
    FILE *vangogh;
    FILE *Grito;
    FILE *Santos;
    Tesla = fopen("tesla.txt", "r");
    vangogh = fopen("vangogh.txt", "r");
    Grito = fopen("grito.txt", "r");
    Santos = fopen("santosDumont.txt", "r");

    if (Tesla == NULL || vangogh == NULL || Grito == NULL || Santos == NULL) {
        printf("Erro ao abrir um dos arquivos de contagem de obras.\n");
        return 1;
    }

    fscanf(Tesla, "%d", &contadorTesla);
    fscanf(Grito, "%d", &contadorGrito);
    fscanf(vangogh, "%d", &contadorVan);
    fscanf(Santos, "%d", &contadorSantos);

    fclose(Tesla);
    fclose(vangogh);
    fclose(Grito);
    fclose(Santos);

    // Encontrar o maior valor
    int tempMaiorValor = contadorTesla;
    int tempObraMaiorValor = 0;

    if (contadorVan > tempMaiorValor) {
        tempMaiorValor = contadorVan;
        tempObraMaiorValor = 1;
    }
    if (contadorGrito > tempMaiorValor) {
        tempMaiorValor = contadorGrito;
        tempObraMaiorValor = 2;
    }
    if (contadorSantos > tempMaiorValor) {
        tempMaiorValor = contadorSantos;
        tempObraMaiorValor = 3;
    }

    // Encontrar o menor valor
    int tempMenorValor = contadorTesla;
    int tempObraMenorValor = 0;

    if (contadorVan < tempMenorValor) {
        tempMenorValor = contadorVan;
        tempObraMenorValor = 1;
    }
    if (contadorGrito < tempMenorValor) {
        tempMenorValor = contadorGrito;
        tempObraMenorValor = 2;
    }
    if (contadorSantos < tempMenorValor) {
        tempMenorValor = contadorSantos;
        tempObraMenorValor = 3;
    }

    // Obter os nomes das obras
    char nomeMaior[50];
    char nomeMenor[50];

    obterNomeObra(tempObraMaiorValor, nomeMaior);
    obterNomeObra(tempObraMenorValor, nomeMenor);
    *maiorValor = tempMaiorValor;
    *menorValor = tempMenorValor;
    strcpy(obraMaiornome, nomeMaior);
    strcpy(obraMenornome, nomeMenor);

    return 0;
}
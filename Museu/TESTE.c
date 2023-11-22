#include <stdio.h>

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

int main() {
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
    int maiorValor = contadorTesla;
    int obraMaiorValor = 0;

    if (contadorVan > maiorValor) {
        maiorValor = contadorVan;
        obraMaiorValor = 1;
    }
    if (contadorGrito > maiorValor) {
        maiorValor = contadorGrito;
        obraMaiorValor = 2;
    }
    if (contadorSantos > maiorValor) {
        maiorValor = contadorSantos;
        obraMaiorValor = 3;
    }

    // Encontrar o menor valor
    int menorValor = contadorTesla;
    int obraMenorValor = 0;

    if (contadorVan < menorValor) {
        menorValor = contadorVan;
        obraMenorValor = 1;
    }
    if (contadorGrito < menorValor) {
        menorValor = contadorGrito;
        obraMenorValor = 2;
    }
    if (contadorSantos < menorValor) {
        menorValor = contadorSantos;
        obraMenorValor = 3;
    }

    // Obter os nomes das obras
    char nomeMaior[50];
    char nomeMenor[50];

    obterNomeObra(obraMaiorValor, nomeMaior);
    obterNomeObra(obraMenorValor, nomeMenor);
    int menorvalorObra = menorValor;
    int maiorValorObra = maiorValor;
    

    // Imprimir os resultados
    printf("Maior valor: %d, Obra: %s\n", maiorValor, nomeMaior);
    printf("Menor valor: %d, Obra: %s\n", menorValor, nomeMenor);

    return 0;
}

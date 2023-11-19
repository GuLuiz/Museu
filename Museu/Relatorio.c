#include <stdio.h>
#include <string.h>
struct Obra
{
    char nome[50];
    char nomeObra[50];
    float notas[4];
};

int Relatorio ()
{
    struct Obra obras[100];
    int indiceobras = 0;
    char linha[256];

    FILE *questionario;
    questionario = fopen("C:\\Museu\\Museu\\output\\Questionario.txt", "r");

    while (fgets(linha, sizeof(linha), questionario) != NULL) {
        if (sscanf(linha, "Usuario: %s", obras[indiceobras].nome) == 1 &&
            fgets(linha, sizeof(linha), questionario) != NULL &&
            sscanf(linha, " Obra: %[^\n]", obras[indiceobras].nomeObra) == 1 &&
            fgets(linha, sizeof(linha), questionario) != NULL &&
            sscanf(linha, " Notas: %f %f %f %f",
                   &obras[indiceobras].notas[0],
                   &obras[indiceobras].notas[1],
                   &obras[indiceobras].notas[2],
                   &obras[indiceobras].notas[3]) == 4) {
            indiceobras++;
        }
    }

    // Fecha o arquivo
    fclose(questionario);

    // Exibe os dados lidos
    for (int i = 0; i < indiceobras; i++) {
        printf("Usuario: %s\n", obras[i].nome);
        printf("Obra: %s\n", obras[i].nomeObra);
        printf("Notas: %.2f %.2f %.2f %.2f\n",
               obras[i].notas[0],
               obras[i].notas[1],
               obras[i].notas[2],
               obras[i].notas[3]);
        printf("\n");
    }

    return 0;
}

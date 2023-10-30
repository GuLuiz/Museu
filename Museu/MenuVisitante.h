#include <stdlib.h>
#include <stdio.h>
#include <String.h>

int MenuVisitante() {
    char nome[50];

    printf("\n***********************************************");
    printf("\nMENU VISITANTE");
    printf("\nDigite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    // Consuma a nova linha deixada pela entrada do nome
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\n1 - Bilheteria");
    printf("\n2 - Obras");
    printf("\n3 - Sair");
    printf("%s", nome);

    return 0;
}
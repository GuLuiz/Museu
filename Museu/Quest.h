#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *CountObras;
void questionario(int obra, char Nome){
    char Username = Nome;
    CountObras = fopen("ObraAcessada.txt", "r");
    int obrasCount[3];
    fscanf(CountObras, "%d %d %d %d", &obrasCount[0], &obrasCount[1], &obrasCount[2], &obrasCount[3]);
    
    if (obra == 1) {
            obrasCount[0] =+ 1;
        }
        else if (obra == 2) {
            obrasCount[1] =+ 1;
        }
        else if (obra == 3) {
            obrasCount[2] =+ 1;
        }
        else if (obra == 4) {
            obrasCount[3] =+ 1;
        }

    CountObras = fopen("ObraAcessada.txt", "w");
    fprintf(CountObras, "%d %d %d %d", obrasCount[0], obrasCount[1], obrasCount[2], obrasCount[3]);
    fclose(CountObras);


    // Questionario Parte
    }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Escrita.h"

const char *entrada = "src/infosdotrabalho.txt";

void informacao(char *texto, int inic, int fim){

    FILE *arq = fopen(entrada, "r");
    char aux[100];
    int cont = 1;

    while(cont < fim){
        fgets(aux, 100, arq);

        if(cont >= inic){
            strcat(texto, aux);
        }
        
        cont++;        
    }

    fclose(arq);
}

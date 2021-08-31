#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MetodosOrdenacao.h"


void ordenacao(int* V, int tam, int ordem){
    int i;

    if(ordem == 0){
        int aux = 0;
        for(i=tam; i>0; i--){
            V[aux] = i;
            aux++;
        }
    }
    else if(ordem == 1){
        for(i=0; i<tam; i++){
            V[i] = i;
        }
    }
    else{
        srand(time(NULL));
        for(i=0; i<tam; i++){
            
            V[i] = (rand() % tam);
        }
    }
}

void bubbleSort(int* V, int N){
    int i , cont, aux, end;
    end = N;

    do{
        cont = 0;
        for(i = 0; i < end-1; i++){     //percorre o array
            if(V[i] > V[i+1]){      //#se o valor for maior que o proximo troca a posição
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                cont = i; 
            }
        }
        
    } while(cont != 0);    //realiza enquanto houver elementos fora da posição
}

void selectionSort(int* V, int N){

    int i, j, aux, troca;

    for(i = 0; i < N-1; i++){     //percorre as posições do array
        aux = i;
        for(j = i+1; j < N; j++){     //percorre o array
            if( V[j] < V[aux]){    //caso encontre um valor menor que o da posição inicial define um novo valor menor
                aux = j;
                
            }
        }
        if(i != aux){     //se o valor menor foi alterado troco as posições
            troca = V[i];
            V[i] = V[aux];
            V[aux] = troca;
        }
    }
}

void insertionSort(int* V, int N){

    int i, j, aux;
    for(i = 1; i < N; i++){     //percorre o array

        aux = V[i];
        for(j = i; (j>0) && (aux < V[j-1]); j--){       // move valores maiores para proxima posição
            V[j] = V[j-1];
        }
        V[j] = aux;     // vetor recebe a o elemento
    }
}

void quickSort(int* V, int inicio, int fim){
    int pivo;

    if(fim > inicio){
        pivo = particao(V, inicio, fim);
        quickSort(V, inicio, pivo-1);       //realiza do inicio até o pivo
        quickSort(V, pivo+1, fim);            //realiza do pivo até o fim
    }
}

//auxiliar

int particao(int* V, int inicio, int fim){
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = fim;
    pivo = V[inicio];

    while(esquerda < direita){

        while(esquerda <= fim && V[esquerda] <= pivo){      //percorre da esquerda para direita
            esquerda++;
        }

        while(direita >= 0 && V[direita] > pivo){           //percorre da direita para esquerda
            direita--;
        }

        if(esquerda < direita){     //inverte a posição
            aux = V[esquerda];
            V[esquerda] = V[direita];
            V[direita] = aux;
        }
    }
    V[inicio] = V[direita];
    V[direita] = pivo;

    return direita;     // retorna o valor do pivo
}
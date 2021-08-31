#ifndef MetodosOrdenacao
#define MetodosOrdenacao


void ordenacao(int* V, int tam, int ordem);

void bubbleSort(int* V, int N);
void selectionSort(int* V, int N);
void insertionSort(int* V, int N);
void quickSort(int* V, int incio, int fim);

//auxiliar

int particao(int* V, int inicio, int fim);


#endif
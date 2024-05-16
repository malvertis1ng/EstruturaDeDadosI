#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VETOR 10000

void calcVetor(int vetor[]){
    srand(42);
    for (int i = 0; i < VETOR; i++){
        vetor[i] = rand() % 10000;
    }
}

void printVetor(int vetor[]){
    for (int i = 0; i < VETOR;i++){
        printf("%d\n", vetor[i]);
    }
}

void bubbleSort(int vetor[]) {
    int i, j, aux;
    for (i = 0; i < VETOR - 1; i++) {
        for (j = 0; j < VETOR - i - 1; j++) {
            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void selectionSort(int vetor[]) {
    int i, j, menor, temp;
    for (i = 0; i < VETOR - 1; i++) {
        menor = i;
        for (j = i+1; j < VETOR; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        temp = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = temp;
    }
}

void insertionSort(int vetor[]) {
    int i, j, chave;
    for (i = 1; i < VETOR; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int vetor[VETOR];

    calcVetor(vetor);

    int vetorBubble[VETOR], vetorSelect[VETOR], vetorInsert[VETOR];
    for (int i = 0; i < VETOR; i++) {
        vetorBubble[i] = vetor[i];
        vetorSelect[i] = vetor[i];
        vetorInsert[i] = vetor[i];
    }

    clock_t inicio = clock();
    bubbleSort(vetorBubble);
    clock_t fim = clock();
    double tempoBubble = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    selectSort(vetorSelect);
    fim = clock();
    double tempoSelect = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    insertSort(vetorInsert);
    fim = clock();
    double tempoInsert = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de execução do Bubble Sort: %.6f segundos\n", tempoBubble);
    printf("Tempo de execução do Selection Sort: %.6f segundos\n", tempoSelect);
    printf("Tempo de execução do Insertion Sort: %.6f segundos\n", tempoInsert);

    return 0;
}
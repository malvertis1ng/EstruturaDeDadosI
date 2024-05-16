#include <stdio.h>

void bubbleSort(int vetor[], int tamanho){
    int i, j, temp;
    for(i = 0; i < tamanho - 1;i++){
        for(j = 0; j<tamanho - i - 1;j++){
            if (vetor[j] > vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main(){
    int vetor[10] = {5, 2, 9, 1, 7, 4, 6, 3, 10, 8};
    int tamanho = 10;
    int i;

    printf("Vetor Original:\n");
    for (i = 0;i < tamanho; i++){
        printf("%d", vetor[i]);
    }
    printf("\n");

    bubbleSort(vetor, tamanho);

    printf("Vetor ordenado usando Bubble Sort:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
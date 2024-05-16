#include <stdio.h>

void selectSort(int vetor[], int n) {
    int i, j, menor;

    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        int aux = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = aux;
    }
}

int main() {
    int arr[] = {10, 7, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Vetor original: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectSort(arr, n);

    printf("Vetor ordenado: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
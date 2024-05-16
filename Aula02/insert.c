#include <stdio.h>

void insertSort(int vetor[], int n){
    int i, chave, j;
    for (i = 1; i < n; i++){
        chave = vetor[i];
        j = i - 1;

        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int main(){
    int vetor[] = {12, 11, 13, 5, 6};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int i;

    printf("Vetor original:\n");
    for (i = 0; i< n;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    insertSort(vetor, n);

    printf("Vetor ordenado:\n");
    for(i = 0; i < n;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
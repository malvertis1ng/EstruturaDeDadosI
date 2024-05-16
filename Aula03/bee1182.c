#include <stdio.h>



int bubbleSort(int *vetor, int tamanho) {
    int trocas = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocas++;
            }
        }
    }
    return trocas;
}


int main(){
    int N;
    scanf("%d", &N);
    
    

    for(int aux=0; aux<N; aux++){
        int tam;
        scanf("%d", &tam);
    

        int ordem_trem[tam];
        for(int j=0; j<tam; j++){
        scanf("%d", &ordem_trem[j]);
        }

        int qtdtrocas = bubbleSort(ordem_trem, tam);
        printf("Optimal train swapping takes %d swaps.\n", qtdtrocas);
    }

    return 0;

}
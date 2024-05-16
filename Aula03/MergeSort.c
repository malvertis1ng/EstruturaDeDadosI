#include<stdio.h>

void merge(int *vetor, int n){
    int meio, i, j, k, aux[n];

    meio = n/2;

    i = 0;
    j = meio;
    k = 0;

    while(i < meio && j < n){

        if(vetor[i] <= vetor[j]){
            aux[k] = vetor[i];
            k++;
            i++;
        }else{
            aux[k] = vetor[j];
            k++;
            j++;
        }

    }

    if(i == meio){
        while(j < n){
            aux[k] = vetor[j];
            k++;
            j++;
        }
    }else{
        while(i < meio){
            aux[k] = vetor[i];
            k++;
            i++;
        }
    }

    for(i=0; i<n; i++){
        vetor[i] = aux[i];
    }

}

void mergesort(int *vetor, int n){
    int meio;

    if(n > 1){
        meio = n / 2;

        mergesort(vetor, meio);
        mergesort(vetor+meio, n-meio);

        merge(vetor, n);
    }

}

int main(){
    int vet[10]={23,45,12,43,13,56,18,42,18,67};
    int i, tam=10;

    for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }

    printf("\n\n");

    mergesort(vet, tam);

     for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}
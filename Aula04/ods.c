#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char estado[30];
    float taxa_2009;
    float taxa_2015;
    float indice_crescimento;
} DadosEstado;

void shellSort(DadosEstado* estados, int num_estados) {
    int i, j, h;
    DadosEstado temp;
    for (h = num_estados/2; h > 0; h /= 2) {
        for (i = h; i < num_estados; i++) {
            temp = estados[i];
            for (j = i; j >= h && estados[j - h].indice_crescimento < temp.indice_crescimento; j -= h) {
                estados[j] = estados[j - h];
            }
            estados[j] = temp;
        }
    }
}

int main() {
    int num_estados = 27; 

    DadosEstado* estados = (DadosEstado*)malloc(num_estados * sizeof(DadosEstado));

    for (int i = 0; i < num_estados; i++) {
        printf("Digite o nome do estado e as taxas de mortalidade neonatal de 2009 e 2015 (exemplo: AC 12.6 10.6): ");
        scanf("%s %f %f", estados[i].estado, &estados[i].taxa_2009, &estados[i].taxa_2015);
        estados[i].indice_crescimento = estados[i].taxa_2015 - estados[i].taxa_2009;
    }

    shellSort(estados, num_estados);

    printf("\nEstado\tTaxa 2009\tTaxa 2015\tÍndice de Crescimento\n");
    for (int i = 0; i < num_estados; i++) {
        printf("%s\t%.2f\t\t%.2f\t\t%.2f\n", estados[i].estado, estados[i].taxa_2009, estados[i].taxa_2015, estados[i].indice_crescimento);
    }

    return 0;
}
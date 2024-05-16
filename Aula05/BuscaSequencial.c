#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 100

typedef struct {
    int RA;
    float nota_A1;
    float nota_A2;
} Aluno;

int lerDados(Aluno alunos[]) {
    FILE *arquivo;
    int i = 0;

    arquivo = fopen("A05naoOrdenado.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (!feof(arquivo) && i < MAX_ALUNOS) {
        fscanf(arquivo, "%d %f %f", &alunos[i].RA, &alunos[i].nota_A1, &alunos[i].nota_A2);
        i++;
    }

    fclose(arquivo);

    return i; 
}


void buscarAlunoSequencial(Aluno alunos[], int num_alunos, int RA) {
    int i;
    for (i = 0; i < num_alunos; i++) {
        if (alunos[i].RA == RA) {
            float nota_final = (alunos[i].nota_A1 + alunos[i].nota_A2) / 2;
            printf("RA: %d\n", alunos[i].RA);
            printf("Nota A1: %.2f\n", alunos[i].nota_A1);
            printf("Nota A2: %.2f\n", alunos[i].nota_A2);
            printf("Nota final: %.2f\n", nota_final);
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", RA);
}


int main() {
    Aluno alunos[MAX_ALUNOS];
    int num_alunos, RA_busca;

    num_alunos = lerDados(alunos);

    printf("Informe o RA do aluno a ser buscado: ");
    scanf("%d", &RA_busca);

    printf("\nBusca sequencial:\n");
    buscarAlunoSequencial(alunos, num_alunos, RA_busca);

    
    return 0;
}
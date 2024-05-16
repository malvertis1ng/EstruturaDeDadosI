#include "header.h"
#include "aluno.c"

int main() {
    Aluno *a;
    int i;

    a = (Aluno*) malloc(5 * sizeof(Aluno));
    if (a == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i + 1);
        ler_dados_aluno(&a[i]);
    }


    for (i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i + 1);
        exibir_dados_aluno(&a[i]);
    }

    printf("\nEndereço de memória do ponteiro 'a': %p\n", (void*)&a);
    printf("Espaço total ocupado na memória por '*a': %zu bytes\n", 5 * sizeof(Aluno));
    printf("\n");

    free(a);

    return 0;
}
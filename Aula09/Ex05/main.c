#include "header.h"
#include "aluno.c"

int main() {
    Aluno a;

    
    ler_dados_aluno(&a);

    
    exibir_dados_aluno(&a);


    printf("\nEndereço de memória do ponteiro 'a': %p\n", (void*)&a);
    printf("Espaço total ocupado na memória por '*a': %zu bytes\n", sizeof(Aluno));
    printf("\n");


    return 0;
}
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ler_dados_aluno(Aluno *a) {
    printf("Digite o RA do aluno: ");
    scanf("%d", &a->RA);
    printf("Digite o nome do aluno: ");
    scanf("%s", a->nome); 
    printf("Digite a idade do aluno: ");
    scanf("%d", &a->idade);
    printf("Digite a nota média do aluno: ");
    scanf("%f", &a->notamedia);
}

void exibir_dados_aluno(Aluno *a) {
    printf("\nDados do Aluno:\n");
    printf("RA: %d\n", a->RA);
    printf("Nome: %s\n", a->nome);
    printf("Idade: %d\n", a->idade);
    printf("Nota Média: %.2f\n", a->notamedia);
    printf("\n");

    printf("Endereço na memória:\n");
    printf("RA: %p\n", (void*)&a->RA);
    printf("Nome: %p\n", (void*)a->nome);
    printf("Idade: %p\n", (void*)&a->idade);
    printf("Nota Média: %p\n", (void*)&a->notamedia);
    printf("\n");

    printf("Tamanho na memória:\n");
    printf("RA: %zu bytes\n", sizeof(a->RA));
    printf("Nome: %zu bytes\n", sizeof(a->nome));
    printf("Idade: %zu bytes\n", sizeof(a->idade));
    printf("Nota Média: %zu bytes\n", sizeof(a->notamedia));
    printf("\n");
}
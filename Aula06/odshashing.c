#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_HASH 97
#define NOME_MAX 30

typedef struct Estado {
  char nome[NOME_MAX];
  char sigla[3];
} Estado;

// Função hash com soma para ASCII
int hashFunction(char *nome) {
  int hashcode = 0;
  for (int i = 0; i < strlen(nome); i++) {
    hashcode += nome[i];
  }
  return hashcode % TAM_HASH;
}

int main() {
  Estado estados[27]; 
  int hashTable[TAM_HASH];
  int colisoes = 0;
  int i;
  char nome[NOME_MAX];
  FILE *arquivo;

  arquivo = fopen("estados.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de dados!\n");
    return 1;
  }

 
  for (i = 0; i < TAM_HASH; i++) {
    hashTable[i] = -1; // posição vazia
  }

  // ler dados do arquivo e inserir na tabela hash
  while (fscanf(arquivo, "%s %s", nome, estados[i].sigla) != EOF) {
    strcpy(estados[i].nome, nome);
    int hashCode = hashFunction(estados[i].nome);
    if (hashTable[hashCode] != -1) {
      colisoes++;
    }
    hashTable[hashCode] = i;
    i++;
  }

  fclose(arquivo);

  //Exibe os estados e suas posições na tabela hash
  for (int i = 0; i < 27; i++) {
    int hashCode = hashFunction(estados[i].nome);
    printf("%s (%s): hashcode %d, posicao %d\n", estados[i].nome, estados[i].sigla,
           hashCode, hashTable[hashCode]);
  }

  printf("Colisões: %d\n", colisoes);

  return 0;
}
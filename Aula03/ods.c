#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DadosODS {
  char estado[30];
  float taxa2009;
  float taxa2015;
  float indice;
};

void trocar(struct DadosODS *a, struct DadosODS *b) {
  struct DadosODS temp = *a;
  *a = *b;
  *b = temp;
}

int pivo(struct DadosODS *dados, int inicio, int fim) {
  float pivo = dados[fim].taxa2015;
  int i = inicio - 1;

  for (int j = inicio; j < fim; j++) {
    if (dados[j].taxa2015 <= pivo) {
      i++;
      trocar(&dados[i], &dados[j]);
    }
  }
  trocar(&dados[i + 1], &dados[fim]);
  return i + 1;
}

void quickSort(struct DadosODS *dados, int inicio, int fim) {
  if (inicio < fim) {
    int pi = pivo(dados, inicio, fim);

    quickSort(dados, inicio, pi - 1);
    quickSort(dados, pi + 1, fim);
  }
}

int main() {
  struct DadosODS dados[27];

  for (int i = 0; i < 27; i++) {
    scanf("%s %f %f", dados[i].estado, &dados[i].taxa2009, &dados[i].taxa2015);
  }


  for (int i = 0; i < 27; i++) {
    dados[i].indice = dados[i].taxa2015 - dados[i].taxa2009;
  }

  quickSort(dados, 0, 26);

  printf("Dados ordenados por índice de mortalidade materna de 2015:\n");
  printf("Estado\tTaxa 2009\tTaxa 2015\tÍndice\n");
  for (int i = 0; i < 27; i++) {
    printf("%s\t%.1f\t\t%.1f\t\t%.1f\n", dados[i].estado, dados[i].taxa2009, dados[i].taxa2015, dados[i].indice);
  }

  return 0;
}
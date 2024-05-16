#include "header.h"

void inicializar_lista(ListaJogadores *lista, int *dados, int tamanho) {
    lista->tamanho = tamanho;
    for (int i = 0; i < tamanho; i++) {
        lista->distancias[i] = dados[i];
    }
}

char verificar_impedimento(ListaJogadores *atacantes, ListaJogadores *defensores) {
    for (int i = 0; i < defensores->tamanho - 1; i++) {
        for (int j = 0; j < defensores->tamanho - i - 1; j++) {
            if (defensores->distancias[j] > defensores->distancias[j + 1]) {
                int temp = defensores->distancias[j];
                defensores->distancias[j] = defensores->distancias[j + 1];
                defensores->distancias[j + 1] = temp;
            }
        }
    }

    
    int minAtacante = atacantes->distancias[0];
    int penultimoDefensor = defensores->distancias[1];

    
    if (minAtacante < penultimoDefensor) {
        return 'Y';
    } else {
        return 'N';
    }
}
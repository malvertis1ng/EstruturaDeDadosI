#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 11


typedef struct {
    int distancias[MAX_PLAYERS];  
    int tamanho; 
    int atacantes;
    int defensores;
} ListaJogadores;
//39173939 		1410 	Ele Está Impedido! 	Accepted 	C99 	0.000 	20/04/2024 19:09  BEEID:813025
#include "header.h"
#include "func.c"


int main() {
    int A, D;
    while (1) {
        scanf("%d %d", &A, &D);
        if (A == 0 && D == 0) {
          
            break;
        }

        int distanciasAtacantes[MAX_PLAYERS];
        for (int i = 0; i < A; i++) {
            scanf("%d", &distanciasAtacantes[i]);
        }

        int distanciasDefensores[MAX_PLAYERS];
        for (int i = 0; i < D; i++) {
            scanf("%d", &distanciasDefensores[i]);
        }

        ListaJogadores atacantes, defensores;
        inicializar_lista(&atacantes, distanciasAtacantes, A);
        inicializar_lista(&defensores, distanciasDefensores, D);

        char resultado = verificar_impedimento(&atacantes, &defensores);

        printf("%c\n", resultado);
    }

    return 0;
}
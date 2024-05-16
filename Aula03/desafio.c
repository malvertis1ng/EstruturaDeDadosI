//ID BEECROWD - 813025

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 105

typedef unsigned short us;

typedef struct {
    int qts_pontos;
    int marcadas;
    int sofridas;
    int id;
} Equipe;

typedef struct {
    Equipe equipe;
    int id;
} Time;

Time times[MAXSIZE];

int compara(const void *a, const void *b) {
    const Time *timeA = (const Time *)a;
    const Time *timeB = (const Time *)b;

    const Equipe *equipeA = &(timeA->equipe);
    const Equipe *equipeB = &(timeB->equipe);

    if (equipeA->qts_pontos != equipeB->qts_pontos)
        return equipeB->qts_pontos - equipeA->qts_pontos;

    float mediaA = (equipeA->sofridas != 0) ? equipeA->marcadas / (float)equipeA->sofridas : 0;
    float mediaB = (equipeB->sofridas != 0) ? equipeB->marcadas / (float)equipeB->sofridas : 0;

    if (mediaA != mediaB)
        return (mediaA > mediaB) ? -1 : 1;

    if (equipeA->marcadas != equipeB->marcadas)
        return equipeB->marcadas - equipeA->marcadas;

    return timeA->id - timeB->id;
}

int main() {
    int n, i;
    int instancia = 0;
    int id1, id2, pt1, pt2;

    while (scanf("%d", &n) == 1) {
        if (n == 0)
            break;

        if (instancia != 0)
            printf("\n");

        us tmp = n * (n - 1) / 2;

        for (i = 1; i <= n; ++i) {
            times[i].equipe.qts_pontos = 0;
            times[i].equipe.marcadas = 0;
            times[i].equipe.sofridas = 0;
            times[i].equipe.id = i;
            times[i].id = i;
        }

        for (i = 0; i < tmp; ++i) {
            scanf("%d %d %d %d", &id1, &pt1, &id2, &pt2);

            Equipe *equipe1 = &(times[id1].equipe);
            Equipe *equipe2 = &(times[id2].equipe);

            if (pt1 > pt2) {
                equipe1->qts_pontos += 2;
                equipe2->qts_pontos += 1;
            } else {
                equipe2->qts_pontos += 2;
                equipe1->qts_pontos += 1;
            }

            equipe1->marcadas += pt1;
            equipe1->sofridas += pt2;
            equipe2->marcadas += pt2;
            equipe2->sofridas += pt1;
        }

        qsort(&times[1], n, sizeof(Time), compara);

        printf("Instancia %d\n", ++instancia);

        for (i = 1; i <= n; ++i) {
            if (i > 1)
                printf(" ");
            printf("%d", times[i].equipe.id);
        }
        printf("\n");
    }

    return 0;
}
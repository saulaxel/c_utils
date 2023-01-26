#include <stdio.h>
#include <stdlib.h>

#include "permutaciones_suma_fija.h"

void comparar_permutacion(size_t N, int perm_obtenida[], int perm_esperada[],
        int num_permutacion)
{
    for (size_t i = 0; i < N; ++i) {
        if (perm_obtenida[i] != perm_esperada[i]) {
            fprintf(stderr, "En la permutación número %d ne esperaba %d pero se obtuvo %d\n",
                    num_permutacion, perm_esperada[i], perm_obtenida[i]);
            exit(EXIT_FAILURE);
        }
    }
}

int main(void)
{
    enum { N = 3 };
    int perm[N];
    int limites[N] = { 2, 1, 2 };
    int suma_esperada = 3;
    int perm_esperadas[][N] = {
        {2, 1, 0},
        {2, 0, 1},
        {1, 1, 1},
        {1, 0, 2},
        {0, 1, 2}
    };

    int num_permutacion = 0;
    minima_permutacion_suma_fija(N, perm, limites, suma_esperada);
    ++num_permutacion;
    comparar_permutacion(N, perm, perm_esperadas[num_permutacion - 1],
            num_permutacion);

    bool hay_permutacion;
    while ( (hay_permutacion = siguiente_permutacion_suma_fija(N, perm, limites)) ) {
        ++num_permutacion;
        comparar_permutacion(N, perm, perm_esperadas[num_permutacion - 1],
                num_permutacion);
    }
}

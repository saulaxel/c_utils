#include "permutaciones_suma_fija.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define FOR_0_TO(var, n) for (size_t var = 0; var < (n); ++var)

size_t primer_indice_no_cero(size_t N, int arr[N])
{
    FOR_0_TO(i, N) {
        if (arr[i] != 0) return i;
    }

    fputs("Todos los índices son 0", stderr);
    exit(EXIT_FAILURE);
}

void minima_permutacion_suma_fija(size_t N, int perm[N], int limites[N], int suma_esperada)
{
    int suma = 0;

    int index = 0;
    while (suma != suma_esperada) {
        int delta = suma_esperada - suma;
        int limite = limites[index];

        if (delta > limite) {
            perm[index] = limite;
            suma += limite;
        } else {
            perm[index] = delta;
            suma += delta;
        }

        ++index;
    }

    for (size_t i = index; i < N; ++i) {
        perm[i] = 0;
    }
}

void reponer_quitado_al_inicio(size_t N, int perm[N], int limites[N], int quitado)
{
    size_t index = 0;

    while (quitado != 0) {
        int delta = limites[index] - perm[index];

        if (delta >= quitado) {
            perm[index] += quitado;
            quitado = 0;
        } else {
            perm[index] += delta;
            quitado -= delta;
            ++index;
        }
    }
}

bool sumar_hasta_siguiente_permutacion(size_t N, int perm[N], int limites[N], size_t a_partir_de)
{
    size_t index = a_partir_de;

    while ( (index < N) && (perm[index] >= limites[index]) ) {
        int quitado = perm[index];
        perm[index] = 0;

        reponer_quitado_al_inicio(N, perm, limites, quitado);

        ++index;
    }

    if (index < N) {
        perm[index] += 1;
        return true; // Se encontró la siguiente permutación
    }

    return false; // Ya no hay más permutaciones
}

bool siguiente_permutacion_suma_fija(size_t N, int perm[N], int limites[N])
{
    // Como todas las permutaciones deben tener la misma suma, cuando quitamos
    // una unidad de un elemento se debe sumar dicha unidad en otro y viceversa

    if (perm[0]) {
        // Se puede quitar una unidad del inicio y pasarla a los otros números
        perm[0] -= 1;

        return sumar_hasta_siguiente_permutacion(
            N, perm, limites, 1
        );
    }

    // Se va a tener que recorrer una unidad que no está al inicio
    size_t indice_no_cero = primer_indice_no_cero(N, perm);
    int quitado = perm[indice_no_cero] - 1;
    perm[indice_no_cero] = 0;

    reponer_quitado_al_inicio(N, perm, limites, quitado);

    return sumar_hasta_siguiente_permutacion(
        N, perm, limites,
        indice_no_cero + 1 // Empezar a sumar después de indice_no_cero
    );
}


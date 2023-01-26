#include <stdio.h>
#include <assert.h>

#include "aritmetica_modular.h"

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(*(arr)))

int main(void)
{

    int pares[] = {0, 2, -2, 20};
    for (size_t i = 0; i < ARRAY_LENGTH(pares); ++i) {
        assert(es_par(pares[i]));
    }

    unsigned upares[] = {0, 20};
    for (size_t i = 0; i < ARRAY_LENGTH(upares); ++i) {
        assert(ues_par(upares[i]));
    }

    int impares[] = {-1, 1, 27};
    for (size_t i = 0; i < ARRAY_LENGTH(impares); ++i) {
        assert(es_impar(impares[i]));
    }

    unsigned uimpares[] = {1, 27};
    for (size_t i = 0; i < ARRAY_LENGTH(uimpares); ++i) {
        assert(ues_impar(uimpares[i]));
    }


    int divisibles[][2] = {{4, 2}, {-49, 7}, {1, 1}};
    for (size_t i = 0; i < ARRAY_LENGTH(divisibles); ++i) {
        assert(es_divisible(divisibles[i][0], divisibles[i][1]));
    }

    unsigned udivisibles[][2] = {{4, 2}, {1, 1}};
    for (size_t i = 0; i < ARRAY_LENGTH(udivisibles); ++i) {
        assert(ues_divisible(udivisibles[i][0], udivisibles[i][1]));
    }

    int no_divisibles[][2] = {{7, 2}, {-5, 2}, {5, 7}};
    for (size_t i = 0; i < ARRAY_LENGTH(no_divisibles); ++i) {
        assert(! es_divisible(no_divisibles[i][0], no_divisibles[i][1]));
    }

    int uno_divisibles[][2] = {{7, 2}, {5, 7}};
    for (size_t i = 0; i < ARRAY_LENGTH(uno_divisibles); ++i) {
        assert(! ues_divisible(uno_divisibles[i][0], uno_divisibles[i][1]));
    }

    // Máximo común divisor
    assert(maximo_comun_divisor(2, 6) == 2);
    assert(maximo_comun_divisor(1, 7) == 1);
    assert(maximo_comun_divisor(7, 7) == 7);

    assert(umaximo_comun_divisor(2u, 6u) == 2u);
    assert(umaximo_comun_divisor(1u, 7u) == 1u);
    assert(umaximo_comun_divisor(7u, 7u) == 7u);

    // Mínimo común múltiplo
    assert(minimo_comun_multiplo(6, 8) == 24);
    assert(minimo_comun_multiplo(5, 7) == 35);
    assert(minimo_comun_multiplo(3, 3) == 3);

    assert(uminimo_comun_multiplo(6u, 8u) == 24u);
    assert(uminimo_comun_multiplo(5u, 7u) == 35u);
    assert(uminimo_comun_multiplo(3u, 3u) == 3u);
}

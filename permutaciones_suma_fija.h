#ifndef PERMUTACIONES_SUMA_FIJA_H
#define PERMUTACIONES_SUMA_FIJA_H

#include <stddef.h>
#include <stdbool.h>

void minima_permutacion_suma_fija(size_t N, int perm[N], int limites[N], int suma_esperada);
bool siguiente_permutacion_suma_fija(size_t N, int perm[N], int limites[N]);

#endif

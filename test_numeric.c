#include "numeric.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>

#define CASO_PRUEBA_SIGNED(funcion, MIN, MAX)                          \
    /* Probando punto medio exacto */                                  \
    assert(funcion(10, 30) == 20 && funcion(30, 10) == 20);            \
    assert(funcion(-10, -30) == -20 && funcion(-30, -10) == -20);      \
                                                                       \
    /* Probando identidad */                                           \
    assert(funcion(5, 5) == 5);                                        \
    assert(funcion(-5, -5) == -5);                                     \
                                                                       \
    /* Probando desbordamiento */                                      \
    assert(funcion(MAX, MAX) == MAX);                                  \
    assert(funcion(MIN, MIN) == MIN);                                  \
    assert(funcion(-MAX, MAX) == 0);                                   \
                                                                       \
    assert(funcion(MAX, MAX - 2) == MAX - 1);                          \
    assert(funcion(MAX - 2, MAX) == MAX - 1);                          \
                                                                       \
    assert(funcion(MIN, MIN + 2) == MIN + 1);                          \
    assert(funcion(MIN + 2, MIN) == MIN + 1);

#define CASO_PRUEBA_UNSIGNED(funcion, MAX)                     \
    /* Probando punto medio exacto */                          \
    assert(funcion(10, 30) == 20);                             \
                                                               \
    /* Probando identidad */                                   \
    assert(funcion(5, 5) == 5);                                \
                                                               \
    /* Probando desbordamiento */                              \
    assert(funcion(MAX, MAX) == MAX);                          \
                                                               \
    assert(funcion(MAX, MAX - 2) == MAX - 1);                  \
    assert(funcion(MAX - 2, MAX) == MAX - 1);

int main(void)
{
    CASO_PRUEBA_SIGNED(mitad_int, INT_MIN, INT_MAX);
    CASO_PRUEBA_UNSIGNED(mitad_uint, UINT_MAX);

    CASO_PRUEBA_SIGNED(mitad_long, LONG_MIN, LONG_MAX);
    CASO_PRUEBA_UNSIGNED(mitad_ulong, ULONG_MAX);

    CASO_PRUEBA_SIGNED(mitad_llong, LLONG_MIN, LLONG_MAX);
    CASO_PRUEBA_UNSIGNED(mitad_ullong, ULLONG_MAX);
}

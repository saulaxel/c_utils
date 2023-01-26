#ifndef CICLOS_H
#define CICLOS_H

#include <stddef.h>
#include <stdint.h>

#define FOR_RANGO(var, inicio, fin, acciones)                       \
    do {                                                            \
        int_fast32_t  _ini  = (inicio), _fin = (fin);               \
        int_fast32_t _delta = (_ini < _fin) ? 1 : -1;               \
        int_fast32_t  _obj  = _fin + _delta;                        \
        for (int_fast32_t var = _ini; var != _obj; var += _delta) { \
            acciones;                                               \
        }                                                           \
    } while (0)

#define FOR_ARR(var, arreglo, acciones)                                      \
    do {                                                                     \
        for (size_t _iter = 0; _iter < TAM_ARREGLO(arreglo); ++_iter) {      \
            typeof((arreglo)[0]) (var) = (arreglo)[_iter];                   \
            { acciones; }                                                    \
        }                                                                    \
    } while (0)

#endif // CICLOS_H

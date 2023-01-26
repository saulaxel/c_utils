#include "permutaciones.h"
#include <stdint.h>
#include <stdbool.h>

#define SIN_CANDIDATOS ((size_t)-1)

#define ALLOC_UNITIALIZED(type, n) (type *) malloc(n * sizeof(type))

static uintmax_t factorial(unsigned n)
{
    uintmax_t f = 1;
    for (size_t i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}

static size_t primero_sin_tomar(size_t * indices_tomados, size_t tope, size_t n,
        size_t minimo_a_tomar)
{
    for (size_t i = minimo_a_tomar; i < n; ++i) {
        bool tomado = false;
        for (size_t j = 0; j < tope; ++j) {
            if (indices_tomados[j] == i) {
                tomado = true;
                break;
            }
        }

        if (!tomado) {
            return i;
        }
    }
    return SIN_CANDIDATOS;
}

size_t permutaciones_ordenadas(size_t n, size_t *** salida)
{
    size_t num_perm = factorial(n);
    (*salida) = ALLOC_UNITIALIZED(size_t *, num_perm);
    for (size_t i = 0; i < num_perm; ++i) {
        (*salida)[i] = ALLOC_UNITIALIZED(size_t, n);
    }

    // Pila para llevar cuenta de los índices ya ocupados
    size_t indices_tomados[n];
    size_t tope = 0;

    size_t nesima_permutacion = 0;

    bool termino = false;

    while (!termino) {

        while (tope < n) {
            size_t nuevo_tomado = primero_sin_tomar(indices_tomados, tope, n, 0);
            indices_tomados[tope++] = nuevo_tomado;
        }

        // Se copia una combinación
        for (size_t i = 0; i < n; ++i) {
            (*salida)[nesima_permutacion][i] = indices_tomados[i];
        }

        // Para tener nuevas elecciones se requiere sacar al menos dos índices
        // de la pila. Si se saca uno, la única elección es volver a meter el índice
        // recién sacado
        tope--;

        // Retrocedemos lo que sea necesario para obtener una nueva secuencia
        size_t minimo_a_tomar = 0;
        size_t candidato_tomar = SIN_CANDIDATOS;
        do {
            if (tope == 0) {
                // No hay más permutaciones_ordenadas a tomar
                termino = true;
            } else {
                size_t ultimo_tomado = indices_tomados[--tope];
                minimo_a_tomar = ultimo_tomado + 1;
                candidato_tomar = primero_sin_tomar(indices_tomados, tope, n, minimo_a_tomar);
            }
        } while (candidato_tomar == SIN_CANDIDATOS && !termino);
        // Si el mínimo a tomar es >= n pero no ha terminado, hay que retroceder
        // un paso más antes de encontrar más permutaciones_ordenadas

        if (!termino) {
            indices_tomados[tope++] = candidato_tomar;
            ++nesima_permutacion;
        }
    }

    return num_perm;
}

void liberar_permutaciones(size_t num_perm, size_t *** indices)
{
    for (size_t i = 0; i < num_perm; ++i) {
        free((*indices)[i]);
    }
    free(*indices);
    *indices = NULL;
}

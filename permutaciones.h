#include <stdlib.h>

size_t permutaciones(size_t n, size_t *** salida);
void liberar_permutaciones(size_t num_permutaciones, size_t *** indices);
size_t permutaciones_ordenadas(size_t n, size_t *** salida);

#define GENERAR_FUNCIONES_PERMUTACIONES_TIPO(tipo)                                     \
    static inline size_t                                                               \
    permutaciones_ ## tipo (size_t n, tipo arreglo[], tipo *** salida) {               \
        size_t ** indices = NULL;                                                      \
        size_t num_permutaciones = permutaciones_ordenadas(n, &indices);               \
        (*salida) = malloc(num_permutaciones * sizeof(tipo *));                        \
        for (size_t i = 0; i < num_permutaciones; ++i) {                               \
            (*salida)[i] = malloc(n * sizeof(tipo));                                   \
            for (size_t j = 0; j < n; ++j) {                                           \
                (*salida)[i][j] = arreglo[indices[i][j]];                              \
            }                                                                          \
        }                                                                              \
        return num_permutaciones;                                                      \
    }                                                                                  \
    static inline void                                                                 \
    liberar_permutaciones_ ## tipo(size_t num_permutaciones, tipo *** permutaciones) { \
        for (size_t i = 0; i < num_permutaciones; ++i) {                               \
            free((*permutaciones)[i]);                                                 \
        }                                                                              \
        free(*permutaciones);                                                          \
        *permutaciones = NULL;                                                         \
    }

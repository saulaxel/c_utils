#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "permutaciones.h"

typedef const char * string;

GENERAR_FUNCIONES_PERMUTACIONES_TIPO(string)

void asegurar_igual(size_t recibido, size_t esperado, const char *msg)
{
    if (recibido != esperado) {
        fprintf(stderr, "Se esperaba %zu y recibió %zu\n", esperado, recibido);
        fputs(msg, stderr);
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    // Elegir entre un solo elemento
    size_t ** perm1 = NULL;
    size_t num_perm1 = permutaciones_ordenadas(1, &perm1);
    asegurar_igual(num_perm1, 1, "Cantidad incorrecta num_perm1");

    asegurar_igual(perm1[0][0], 0, "Error en un elemento");
    liberar_permutaciones(num_perm1, &perm1);

    // Elegir entre dos elementos
    size_t esperado2[2][2] = {
        {0, 1},
        {1, 0}
    };
    size_t ** perm2 = NULL;
    size_t num_perm2 = permutaciones_ordenadas(2, &perm2);
    asegurar_igual(num_perm2, 2, "Cantidad incorrecta num_perm2");
    for (size_t i = 0; i < num_perm2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            asegurar_igual(perm2[i][j], esperado2[i][j],
                    "Error en dos elementos");
        }
    }
    liberar_permutaciones(num_perm2, &perm2);

    // Elegir entre tres elementos
    size_t ** perm3 = NULL;
    size_t num_perm3 = permutaciones_ordenadas(3, &perm3);
    asegurar_igual(num_perm3, 6, "Cantidad incorrecta num_perm3");
    size_t esperado3[6][3] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };
    for (size_t i = 0; i < num_perm3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            asegurar_igual(perm3[i][j], esperado3[i][j],
                    "Error en tres elementos");
        }
    }
    liberar_permutaciones(num_perm3, &perm3);

    // Elegir entre cadenas
    const char * cads[] = {
        "uno", "dos", "tres"
    };
    const char *esperado_cad[6][3] = {
        {"uno", "dos", "tres"},
        {"uno", "tres", "dos"},
        {"dos", "uno", "tres"},
        {"dos", "tres", "uno"},
        {"tres", "uno", "dos"},
        {"tres", "dos", "uno"},
    };

    const char *** perm_cad = NULL;
    size_t num_perm_cad = permutaciones_string(3, cads, &perm_cad);
    for (size_t i= 0; i < num_perm_cad; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            asegurar_igual((uintptr_t)perm_cad[i][j], (uintptr_t)esperado_cad[i][j],
                    "Error en tres cadenas");
        }
    }
    liberar_permutaciones_string(num_perm_cad, &perm_cad);
}

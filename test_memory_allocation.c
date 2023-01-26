#include <stdio.h>
#include "utilidades_comunes.h"
#include "memory_allocation.h"

int main(void)
{
    int * arreglo_inicializado = NUEVO_ARR(10, int, true);
    int * arreglo_no_inicializado = NUEVO_ARR(10, int, false);

    puts("El arreglo inicializado contiene: ");
    FOR_RANGO(i, 0, 9, printf("%d ", arreglo_inicializado[i]));
    puts("\nEl arreglo no inicializado contiene: ");
    FOR_RANGO(i, 0, 9, printf("%d ", arreglo_no_inicializado[i]));
    puts("");

    typedef struct {
        int x;
        double y;
    } Estructura;

    int * var_en_cero = NUEVO(int);
    Estructura * var2_en_cero = NUEVO(Estructura);

    printf("El valor de var_en_cero es: %d\n", *var_en_cero);
    assert(*var_en_cero == 0);
    printf("El valor de var2_en_cero es: x = %d, y = %f\n",
            var2_en_cero->x, var2_en_cero->y);
    assert(var2_en_cero->x == 0 && var2_en_cero->y == 0);

    int * primitivo_inicializado = NUEVO_PRIMITIVO(int, 200);
    Estructura * struct_inicializada = NUEVA_STRUCT(Estructura,
                                                    .x = 10, .y = 20);

    printf("El valor de \"primitivo_inicializado\" es: %d\n",
            *primitivo_inicializado);
    printf("El valor de \"struct_inicializada\" es: x = %d, y = %f\n",
            struct_inicializada->x, struct_inicializada->y);
    assert(*primitivo_inicializado == 200);
    assert(struct_inicializada->x == 10 && struct_inicializada->y == 20);

    LIBERAR_ARGS(var_en_cero, var2_en_cero,
                 primitivo_inicializado, struct_inicializada);
}

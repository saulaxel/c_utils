#include "utilidades_comunes.h"

// *. ¿Qué es una prueba de unidad? Ventajas de las pruebas de unidad
// *. ¿Por qué este archivo no funciona como prueba de unidad?

#undef NDEBUG

void printInt(int arg)
{
    printf("%d\n", arg);
}

static int g_array[10] = { 0 };
static int g_top = 0;
void saveIntGlobally(int val)
{
    assert((unsigned)g_top < TAM_ARREGLO(g_array));
    g_array[g_top++] = val;
}

int main(void)
{
    char arreglo[BUFSIZ];
    // 74. ¿Qué es la macro BUFSIZ y para qué sirve?
    IMPRIMIR("Probando las funciones de la cabecera \"utilidades\"");
    IMPRIMIR("Presione enter para continuar . . .");
    LEER_ARR_CHAR(arreglo);

    // ######################################################################

    IMPRIMIR("Probando MAXIMO y MINIMO");

    assert(MAXIMO(5, 1) == 5 && MINIMO(5, 1) == 1);
    assert(MAXIMO(10.5, 50.4) == 50.4 && MINIMO(10.5, 50.4) == 10.5);
    assert(MAXIMO(-10, -20) == -10 && MINIMO(-10, -20) == -20);
    assert(MAXIMO(-101.2, 10) == 10 && MINIMO(-101.2, 10) == -101.2);

    IMPRIMIR("Las macros máximo y mínimo se comportan correctamente");
    LEER_ARR_CHAR(arreglo);

    // ######################################################################

    IMPRIMIR("Probando MAXIMO_VECTOR y MINIMO_VECTOR");

    assert(MAXIMO_VECTOR(5, 4) == 5);
    assert(MINIMO_VECTOR(5, 4) == 4);
    assert(MAXIMO_VECTOR(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 10);
    assert(MINIMO_VECTOR(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 1);
    assert(MAXIMO_VECTOR(10, 20, 5, -1, 9) == 20);
    assert(MINIMO_VECTOR(10, 20, 5, -1, 9) == -1);
    assert(MAXIMO_VECTOR(0.5, 0.7, -1.1, 2.3, 0.43) == 2.3);
    assert(MINIMO_VECTOR(0.5, 0.7, -1.1, 2.3, 0.43) == -1.1);

    IMPRIMIR("Las macros MAXIMO_VECTOR y MINIMO_VECTOR se comportan correctamente");
    LEER_ARR_CHAR(arreglo);

    // ######################################################################

    IMPRIMIR("Funciones de comparación de dobles");

    // 1% de epsilon
    assert(COMPARAR_CON_EPSILON(10, 10.099, 1.0 / 100) == true);
    assert(COMPARAR_CON_EPSILON(10, 10.101, 1.0 / 100) == false);

    // 5% de epsilon
    assert(COMPARAR_CON_EPSILON(1000, 950.1, 5.0 / 100) == true);
    assert(COMPARAR_CON_EPSILON(1000, 949.9, 5.0 / 100) == false);

    // 0.1% de epsilon
    assert(COMPARAR_CON_EPSILON(1, 1.0009 , 0.1 / 100) == true);
    assert(COMPARAR_CON_EPSILON(1, 1.0011 , 0.1 / 100) == false);

    IMPRIMIR("La macro COMPARAR_CON_EPSILON funciona correctamente");
    LEER_ARR_CHAR(arreglo);

    // ######################################################################

    IMPRIMIR("Funciones de promedio");

    const double porciento_error = 1.0 / 100;
    assert(COMPARAR_CON_EPSILON(
                PROMEDIO(8, -1, -2, 23), 7, porciento_error) == true);
    assert(COMPARAR_CON_EPSILON(
                PROMEDIO(5.5, 10.5, 14.0), 10, porciento_error) == true);
    assert(COMPARAR_CON_EPSILON(
                PROMEDIO(0.1L, 0.2L), 0.15, porciento_error) == true);
#ifndef __STDC_NO_COMPLEX__
    assert(COMPARAR_CON_EPSILON(
                PROMEDIO(10 - 5i, 1 + 2i, 4), 5 - 1i, porciento_error) == true);

    assert(COMPARAR_CON_EPSILON(
                PROMEDIO(-5.0L + 10.0Li, -15.0L + 20.0Li), -10 + 15i, porciento_error) == true);
#endif

    IMPRIMIR("Las macros de promedio se comportan correctamente");
    LEER_ARR_CHAR(arreglo);

    // ######################################################################

    IMPRIMIR("Probando los números aleatorios: ");

    plantarSemilla();
    IMPRIMIR(" Aleatorios entre 0 y 9: ");
    FOR_RANGO(n, 1, 10, IMPRIMIR("\t %d", ALEATORIO(9)));
    LEER_ARR_CHAR(arreglo);

    IMPRIMIR(" Aleatorios entre -15 y 30: ");
    FOR_RANGO(n, 1, 10, IMPRIMIR("\t %d", ALEATORIO(-15, 30)));

    LEER_ARR_CHAR(arreglo);

    // ######################################################################

    LEER_ARR_CHAR(arreglo);

    // ######################################################################
    APLICAR_A_LISTA_ESTATICA(int, printInt, 1, 2, 3);

    APLICAR_A_LISTA_ESTATICA(int, saveIntGlobally, 9, 1, 2, 5, 4);
    assert(g_array[0] == 9);
    assert(g_array[1] == 1);
    assert(g_array[2] == 2);
    assert(g_array[3] == 5);
    assert(g_array[4] == 4);
}

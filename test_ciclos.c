#include "ciclos.h"
#include "utilidades_comunes.h"

int main(void)
{
    IMPRIMIR("Probando los rangos: ");
    IMPRIMIR(" Rango de 10 a 20");

    bool ciclo_iniciado = false;
    int primero;
    int ultimo;

    FOR_RANGO(i, 10, 20,

        if (!ciclo_iniciado)
        {
            ciclo_iniciado = true;
            primero = i;
        }
        ultimo = i;

        IMPRIMIR("\t i = %zd", i);
    );
    assert(primero == 10 && ultimo == 20);

    ciclo_iniciado = false;
    IMPRIMIR(" Rango de 5 a -3");
    FOR_RANGO(i, 5, -3,

        if (!ciclo_iniciado)
        {
            ciclo_iniciado = true;
            primero = i;
        }
        ultimo = i;
        IMPRIMIR("\t i = %zd", i);
    );
    assert(primero == 5 && ultimo == -3);

    IMPRIMIR(" Rango de 0 a 0");
    ciclo_iniciado = false;
    FOR_RANGO(i, 0, 0,

        if (!ciclo_iniciado)
        {
            ciclo_iniciado = true;
            primero = i;
        }
        ultimo = i;

        IMPRIMIR("\t i = %zd", i);
    );
    assert(primero == 0 && ultimo == 0);

    int contador = 0;

    REPEAT(10) { contador++; }
    assert(contador == 10);

    contador = 0;
    REPEAT(0) { contador++; }
    assert(contador == 0);

    IMPRIMIR("Los rangos se comportan correctamente");

    IMPRIMIR("Probando la iteración de arreglos: ");

    int arreglo_entero[] = { 7, 4, 21, -99, 1, -13, -14 };
    FOR_ARR(num, arreglo_entero,
        IMPRIMIR("El entero es: %d", num)
    );

    char arreglo_caracteres[] = "abcdefghijkl...";
    FOR_ARR(c, arreglo_caracteres,
        IMPRIMIR("El carácter es: %c", c);
    );

}

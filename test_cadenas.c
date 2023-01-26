#include <stdio.h>
#include <locale.h>
#include <assert.h>

#include "cadenas.h"

int main(void)
{
    assert(cadIguales("cadena", "cadena") == true);
    assert(wcadIguales(L"cadena", L"cadena") == true);

    assert(cadIguales("pan casero", "pan cacero") == false);
    assert(wcadIguales(L"pan casero", L"pan cacero") == false);

    assert(cadIgualesN("acondicionamiento", "acolito", 3) == true);
    assert(wcadIgualesN(L"acondicionamiento", L"acolito", 3) == true);

    assert(cadIgualesN("franciscano", "francotirador", 6) == false);
    assert(wcadIgualesN(L"franciscano", L"francotirador", 6) == false);

    assert(setlocale(LC_ALL, "es_MX.UTF-8"));

    // Se modifica la cadena en cada prueba, y se tiene que tomar en cuenta su
    // nuevo valor
    char prueba[] = "abcd";
    wchar_t wprueba[] = L"Hola, ¿Qué está pasando por aquí?";
    wchar_t wprueba2[] = L"áÉ";
    assert(wcadIguales(L"ÁÉ", wcadMayus(wprueba2)) == true);

    assert(cadIguales("ABCD", cadMayus(prueba)) == true);
    assert(wcadIguales(L"HOLA, ¿QUÉ ESTÁ PASANDO POR AQUÍ?", wcadMayus(wprueba)) == true);

    assert(cadIguales("abcd", cadMinus(prueba)) == true);
    assert(wcadIguales(L"hola, ¿qué está pasando por aquí?", wcadMinus(wprueba)) == true);

    assert(cadIguales("dcba", cadReversa(prueba)) == true);
    assert(wcadIguales(L"?íuqa rop odnasap átse éuq¿ ,aloh", wcadReversa(wprueba)) == true);
}

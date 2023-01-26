#include "array_sorting_searching_primitives.h"
#include "array_sorting_searching_stdint.h"
#include "array_sorting_searching_stdsize.h"
#include "array_sorting_searching_str.h"

#include <assert.h>
#include <stdio.h>

_Bool str_equal(const char * a, const char * b) {
    return strcmp(a, b) == 0;
}

_Bool wstr_equal(const wchar_t * a, const wchar_t * b) {
    return wcscmp(a, b) == 0;
}

int main(void)
{
#define NUMERIC_TEST_CASE(tipo, ordenar, buscar_lineal, buscar_binaria) \
    do {                                                                \
        tipo desordenado[] = { 6, 4, 10, 8, 2 };                        \
        tipo ordenado[] = { 2, 4, 6, 8, 10 };                           \
        ordenar(5, desordenado);                                        \
        for (size_t i = 0; i < 5; ++i) {                                \
            assert(desordenado[i] == ordenado[i]);                      \
        }                                                               \
        /* Buscando elementos que si están presentes */                 \
        for (long i = 1; i <= 5; ++i) {                                 \
            long indice_l = buscar_lineal(5, ordenado, i * 2);          \
            long indice_b = buscar_lineal(5, ordenado, i * 2);          \
            assert(indice_l == indice_b && indice_b == i - 1);          \
        }                                                               \
        /* Buscando elementos que no están presentes */                 \
        /* La búsqueda lineal debe dar -1, pero la búsqueda binaria     \
           debe regresar -(indice_sugerido + 1), que da un indicio      \
           del lugar donde insertar el elemento para preservar          \
           el orden */                                                  \
        for (long i = 1; i <= 6; ++i) {                                 \
            long indice_l = buscar_lineal(5, ordenado, i * 2 - 1);      \
            long indice_b = buscar_binaria(5, ordenado, i * 2 - 1);     \
            assert(indice_l == -1);                                     \
            assert(indice_b == -i);                                     \
        }                                                               \
    } while (0)

    NUMERIC_TEST_CASE(signed char, schar_sort, schar_lsearch, schar_bsearch);
    NUMERIC_TEST_CASE(unsigned char, uchar_sort, uchar_lsearch, uchar_bsearch);
    NUMERIC_TEST_CASE(short, short_sort, short_lsearch, short_bsearch);
    NUMERIC_TEST_CASE(unsigned short, ushort_sort, ushort_lsearch, ushort_bsearch);
    NUMERIC_TEST_CASE(int, int_sort, int_lsearch, int_bsearch);
    NUMERIC_TEST_CASE(unsigned, uint_sort, uint_lsearch, uint_bsearch);
    NUMERIC_TEST_CASE(long, long_sort, long_lsearch, long_bsearch);
    NUMERIC_TEST_CASE(long unsigned, ulong_sort, ulong_lsearch, ulong_bsearch);
    NUMERIC_TEST_CASE(long long, llong_sort, llong_lsearch, llong_bsearch);
    NUMERIC_TEST_CASE(unsigned long long, ullong_sort, ullong_lsearch, ullong_bsearch);

    NUMERIC_TEST_CASE(float, float_sort, float_lsearch, float_bsearch);
    NUMERIC_TEST_CASE(double, double_sort, double_lsearch, double_bsearch);
    NUMERIC_TEST_CASE(long double, ldouble_sort, ldouble_lsearch, ldouble_bsearch);

    NUMERIC_TEST_CASE(int8_t, int8_sort, int8_lsearch, int8_bsearch);
    NUMERIC_TEST_CASE(uint8_t, uint8_sort, uint8_lsearch, uint8_bsearch);
    NUMERIC_TEST_CASE(int16_t, int16_sort, int16_lsearch, int16_bsearch);
    NUMERIC_TEST_CASE(uint16_t, uint16_sort, uint16_lsearch, uint16_bsearch);
    NUMERIC_TEST_CASE(int32_t, int32_sort, int32_lsearch, int32_bsearch);
    NUMERIC_TEST_CASE(uint32_t, uint32_sort, uint32_lsearch, uint32_bsearch);
    NUMERIC_TEST_CASE(int64_t, int64_sort, int64_lsearch, int64_bsearch);
    NUMERIC_TEST_CASE(uint64_t, uint64_sort, uint64_lsearch, uint64_bsearch);

    NUMERIC_TEST_CASE(int_least8_t, intleast8_sort, intleast8_lsearch, intleast8_bsearch);
    NUMERIC_TEST_CASE(uint_least8_t, uintleast8_sort, uintleast8_lsearch, uintleast8_bsearch);
    NUMERIC_TEST_CASE(int_least16_t, intleast16_sort, intleast16_lsearch, intleast16_bsearch);
    NUMERIC_TEST_CASE(uint_least16_t, uintleast16_sort, uintleast16_lsearch, uintleast16_bsearch);
    NUMERIC_TEST_CASE(int_least32_t, intleast32_sort, intleast32_lsearch, intleast32_bsearch);
    NUMERIC_TEST_CASE(uint_least32_t, uintleast32_sort, uintleast32_lsearch, uintleast32_bsearch);
    NUMERIC_TEST_CASE(int_least64_t, intleast64_sort, intleast64_lsearch, intleast64_bsearch);
    NUMERIC_TEST_CASE(uint_least64_t, uintleast64_sort, uintleast64_lsearch, uintleast64_bsearch);

    NUMERIC_TEST_CASE(size_t, sizet_sort, sizet_lsearch, sizet_bsearch);


#define STRING_TEST_CASE(tipo, ordenar, buscar_lineal, buscar_binaria, igual, desordenado, ordenado, busqueda) \
    do {                                                                                                       \
        ordenar(5, desordenado);                                                                               \
        for (size_t i = 0; i < 5; ++i) {                                                                       \
            assert(igual(desordenado[i], ordenado[i]));                                                        \
        }                                                                                                      \
        /* Buscando elementos que si están presentes */                                                        \
        for (long i = 1; i < 5; ++i) {                                                                         \
            long indice_l = buscar_lineal(5, ordenado, ordenado[i]);                                           \
            long indice_b = buscar_lineal(5, ordenado, ordenado[i]);                                           \
            assert(indice_l == indice_b && indice_b == i);                                                     \
        }                                                                                                      \
        /* Buscando elementos que no están presentes */                                                        \
        /* La búsqueda lineal debe dar -1, pero la búsqueda binaria                                            \
           debe regresar -(indice_sugerido + 1), que da un indicio                                             \
           del lugar donde insertar el elemento para preservar                                                 \
           el orden */                                                                                         \
        for (long i = 0; i < 6; ++i) {                                                                         \
            long indice_l = buscar_lineal(5, ordenado, busqueda[i]);                                           \
            long indice_b = buscar_binaria(5, ordenado, busqueda[i]);                                          \
            assert(indice_l == -1);                                                                            \
            assert(indice_b == -(i + 1));                                                                      \
        }                                                                                                      \
    } while (0)

    const char * desordenado[] = { "cc", "bb", "ee", "dd", "aa" };
    const char * ordenado[] = { "aa", "bb", "cc", "dd", "ee" };
    const char * busqueda[] = { "a0", "b0", "c0", "d0", "e0", "f0" };

    const wchar_t * L_desordenado[] = { L"cc", L"bb", L"ee", L"dd", L"aa" };
    const wchar_t * L_ordenado[] = { L"aa", L"bb", L"cc", L"dd", L"ee" };
    const wchar_t * L_busqueda[] = { L"a0", L"b0", L"c0", L"d0", L"e0", L"f0" };

    STRING_TEST_CASE(const char *, str_sort, str_lsearch, str_bsearch, str_equal, desordenado, ordenado, busqueda);
    STRING_TEST_CASE(const wchar_t *, wstr_sort, wstr_lsearch, wstr_bsearch, wstr_equal, L_desordenado, L_ordenado, L_busqueda);
}

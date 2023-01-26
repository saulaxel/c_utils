#include "generic_str_cmp.h"
#include "generic_primitive_cmp.h"
#include "generic_stdint_cmp.h"
#include "generic_stdsize_cmp.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

_Bool str_equal(const char * a, const char * b) {
    return strcmp(a, b) == 0;
}

_Bool wstr_equal(const wchar_t * a, const wchar_t * b) {
    return wcscmp(a, b) == 0;
}

int main(void)
{
    const char *sin_orden[] = {
        "eeee",
        "cccc",
        "aaaa",
        "bbbb",
        "ffff",
        "dddd"
    };
    const char *en_orden[] = {
        "aaaa",
        "bbbb",
        "cccc",
        "dddd",
        "eeee",
        "ffff"
    };
    size_t n = 6;

    // Se ordena y deja de ser "sin_orden"
    qsort(sin_orden, n, sizeof(char *), void_strcmp);

    for (size_t i = 0; i < n; ++i) {
        assert(str_equal(sin_orden[i], en_orden[i]));
    }

    puts("Test for const char (void_strcmp) has passed");

    const wchar_t * L_sin_orden[] = {
        L"eeee",
        L"cccc",
        L"aaaa",
        L"bbbb",
        L"ffff",
        L"dddd"
    };
    const wchar_t * L_en_orden[] = {
        L"aaaa",
        L"bbbb",
        L"cccc",
        L"dddd",
        L"eeee",
        L"ffff"
    };

    // Se ordena y deja de ser "sin_orden"
    qsort(L_sin_orden, n, sizeof(wchar_t *), void_wstrcmp);

    for (size_t i = 0; i < n; ++i) {
        assert(wstr_equal(L_sin_orden[i], L_en_orden[i]));
    }
    puts("Test for const wchar_t (void_wstrcmp) has passed");

#define numeric_test_case(type, function) \
    do {\
        type a = 1;\
        type b = 2;\
        assert(function((const void *)& a, (const void *)&b));\
        puts("Test for " #type " (" #function ") has passed");\
    } while (0)

    numeric_test_case(signed char, void_scharcmp);
    numeric_test_case(unsigned char, void_ucharcmp);
    numeric_test_case(short, void_shortcmp);
    numeric_test_case(int, void_intcmp);
    numeric_test_case(unsigned, void_uintcmp);
    numeric_test_case(long, void_longcmp);
    numeric_test_case(unsigned long, void_ulongcmp);
    numeric_test_case(long long, void_llongcmp);
    numeric_test_case(unsigned long long, void_ullongcmp);

    numeric_test_case(float, void_floatcmp);
    numeric_test_case(double, void_doublecmp);
    numeric_test_case(long double, void_ldoublecmp);

    numeric_test_case(size_t, void_sizetcmp);

    numeric_test_case(int8_t, void_int8cmp);
    numeric_test_case(uint8_t, void_uint8cmp);
    numeric_test_case(int16_t, void_int16cmp);
    numeric_test_case(uint16_t, void_uint16cmp);
    numeric_test_case(int32_t, void_int32cmp);
    numeric_test_case(uint32_t, void_uint32cmp);
    numeric_test_case(int64_t, void_int64cmp);
    numeric_test_case(uint64_t, void_uint64cmp);

    numeric_test_case(int_least8_t, void_intleast8cmp);
    numeric_test_case(uint_least8_t, void_uintleast8cmp);
    numeric_test_case(int_least16_t, void_intleast16cmp);
    numeric_test_case(uint_least16_t, void_uintleast16cmp);
    numeric_test_case(int_least32_t, void_intleast32cmp);
    numeric_test_case(uint_least32_t, void_uintleast32cmp);
    numeric_test_case(int_least64_t, void_intleast64cmp);
    numeric_test_case(uint_least64_t, void_uintleast64cmp);
}


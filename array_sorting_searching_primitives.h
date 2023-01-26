#ifndef ARRAY_SORTING_SEARCHING_PRIMITIVES_H
#define ARRAY_SORTING_SEARCHING_PRIMITIVES_H

#include "array_sorting_searching.h"
#include "generic_primitive_cmp.h"

// Enteros primitivos
ARRAY_FUNCTIONS(signed char, schar, void_scharcmp);
ARRAY_FUNCTIONS(unsigned char, uchar, void_ucharcmp);
ARRAY_FUNCTIONS(short, short, void_shortcmp);
ARRAY_FUNCTIONS(unsigned short, ushort, void_shortcmp);
ARRAY_FUNCTIONS(int, int, void_intcmp);
ARRAY_FUNCTIONS(unsigned, uint, void_uintcmp);
ARRAY_FUNCTIONS(long, long, void_longcmp);
ARRAY_FUNCTIONS(unsigned long, ulong, void_ulongcmp);
ARRAY_FUNCTIONS(long long, llong, void_llongcmp);
ARRAY_FUNCTIONS(unsigned long long, ullong, void_ullongcmp);

// Flotantes
ARRAY_FUNCTIONS(float, float, void_floatcmp);
ARRAY_FUNCTIONS(double, double, void_doublecmp);
ARRAY_FUNCTIONS(long double, ldouble, void_ldoublecmp);

#endif // ARRAY_SORTING_SEARCHING_PRIMITIVES_H

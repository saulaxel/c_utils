#ifndef GENERIC_PRIMITIVE_CMP_H
#define GENERIC_PRIMITIVE_CMP_H

#include "generic_cmp.h"

// Enteros primitivos
GENERIC_NUMERIC_CMP(signed char, void_scharcmp);
GENERIC_NUMERIC_CMP(unsigned char, void_ucharcmp);
GENERIC_NUMERIC_CMP(short, void_shortcmp);
GENERIC_NUMERIC_CMP(int, void_intcmp);
GENERIC_NUMERIC_CMP(unsigned, void_uintcmp);
GENERIC_NUMERIC_CMP(long, void_longcmp);
GENERIC_NUMERIC_CMP(unsigned long, void_ulongcmp);
GENERIC_NUMERIC_CMP(long long, void_llongcmp);
GENERIC_NUMERIC_CMP(unsigned long long, void_ullongcmp);

// Flotantes
GENERIC_NUMERIC_CMP(float, void_floatcmp);
GENERIC_NUMERIC_CMP(double, void_doublecmp);
GENERIC_NUMERIC_CMP(long double, void_ldoublecmp);

#endif // GENERIC_PRIMITIVE_CMP_H

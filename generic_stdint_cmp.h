#ifndef GENERIC_STDINT_CMP_H
#define GENERIC_STDINT_CMP_H

#include "generic_cmp.h"
#include "stdint.h"

// Enteros de tamaño fijo
GENERIC_NUMERIC_CMP(int8_t, void_int8cmp);
GENERIC_NUMERIC_CMP(uint8_t, void_uint8cmp);
GENERIC_NUMERIC_CMP(int16_t, void_int16cmp);
GENERIC_NUMERIC_CMP(uint16_t, void_uint16cmp);
GENERIC_NUMERIC_CMP(int32_t, void_int32cmp);
GENERIC_NUMERIC_CMP(uint32_t, void_uint32cmp);
GENERIC_NUMERIC_CMP(int64_t, void_int64cmp);
GENERIC_NUMERIC_CMP(uint64_t, void_uint64cmp);

// Enteros de tamaño mínimo
GENERIC_NUMERIC_CMP(int_least8_t, void_intleast8cmp);
GENERIC_NUMERIC_CMP(uint_least8_t, void_uintleast8cmp);
GENERIC_NUMERIC_CMP(int_least16_t, void_intleast16cmp);
GENERIC_NUMERIC_CMP(uint_least16_t, void_uintleast16cmp);
GENERIC_NUMERIC_CMP(int_least32_t, void_intleast32cmp);
GENERIC_NUMERIC_CMP(uint_least32_t, void_uintleast32cmp);
GENERIC_NUMERIC_CMP(int_least64_t, void_intleast64cmp);
GENERIC_NUMERIC_CMP(uint_least64_t, void_uintleast64cmp);

#endif // GENERIC_STDINT_CMP_H

#ifndef ARRAY_SORTING_SEARCHING_STDINT_H
#define ARRAY_SORTING_SEARCHING_STDINT_H

#include "array_sorting_searching.h"
#include "generic_stdint_cmp.h"

// Enteros de tamaño fijo
ARRAY_FUNCTIONS(int8_t, int8, void_int8cmp);
ARRAY_FUNCTIONS(uint8_t, uint8, void_uint8cmp);
ARRAY_FUNCTIONS(int16_t, int16, void_int16cmp);
ARRAY_FUNCTIONS(uint16_t, uint16, void_uint16cmp);
ARRAY_FUNCTIONS(int32_t, int32, void_int32cmp);
ARRAY_FUNCTIONS(uint32_t, uint32, void_uint32cmp);
ARRAY_FUNCTIONS(int64_t, int64, void_int64cmp);
ARRAY_FUNCTIONS(uint64_t, uint64, void_uint64cmp);

// Enteros de tamaño mínimo
ARRAY_FUNCTIONS(int_least8_t, intleast8, void_intleast8cmp);
ARRAY_FUNCTIONS(uint_least8_t, uintleast8, void_uintleast8cmp);
ARRAY_FUNCTIONS(int_least16_t, intleast16, void_intleast16cmp);
ARRAY_FUNCTIONS(uint_least16_t, uintleast16, void_uintleast16cmp);
ARRAY_FUNCTIONS(int_least32_t, intleast32, void_intleast32cmp);
ARRAY_FUNCTIONS(uint_least32_t, uintleast32, void_uintleast32cmp);
ARRAY_FUNCTIONS(int_least64_t, intleast64, void_intleast64cmp);
ARRAY_FUNCTIONS(uint_least64_t, uintleast64, void_uintleast64cmp);

#endif // ARRAY_SORTING_SEARCHING_STDINT_H

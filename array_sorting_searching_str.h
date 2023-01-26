#ifndef ARRAY_SORTING_SEARCHING_STR_H
#define ARRAY_SORTING_SEARCHING_STR_H

#include "array_sorting_searching.h"
#include "generic_str_cmp.h"

ARRAY_FUNCTIONS(const char *, str, void_strcmp);
ARRAY_FUNCTIONS(const wchar_t *, wstr, void_wstrcmp);

#endif // ARRAY_SORTING_SEARCHING_STR_H

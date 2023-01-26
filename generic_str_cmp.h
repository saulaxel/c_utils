#ifndef GENERIC_STR_CMP_H
#define GENERIC_STR_CMP_H

#include "generic_cmp.h"
#include <string.h>
#include <wchar.h>

GENERIC_WRAP_CMP(const char *, strcmp, void_strcmp);
GENERIC_WRAP_CMP(const wchar_t *, wcscmp, void_wstrcmp);

#endif // GENERIC_STR_CMP_H

#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <stdbool.h>

#include "intercambiar.h"
#include "ciclos.h"

static inline bool cadIguales(const char * p1,
                              const char * p2)
{
    return (strcmp(p1, p2) == 0);
}
static inline bool wcadIguales(const wchar_t * p1,
                               const wchar_t * p2)
{
    return (wcscmp(p1, p2) == 0);
}

static inline bool cadIgualesN(const char * p1,
                               const char * p2,
                               size_t n)
{
    return (strncmp(p1, p2, n) == 0);
}
static inline bool wcadIgualesN(const wchar_t * p1,
                                const wchar_t * p2,
                                size_t n)
{
    return (wcsncmp(p1, p2, n) == 0);
}

static inline char * cadMayus(char * cad)
{
    FOR_RANGO(i, 0, strlen(cad) - 1, cad[i] = toupper(cad[i]));
    return cad;
}
static inline wchar_t * wcadMayus(wchar_t * wcad)
{
    FOR_RANGO(i, 0, wcslen(wcad) - 1, wcad[i] = towupper(wcad[i]));
    return wcad;
}

static inline char * cadMinus(char * cad)
{
    FOR_RANGO(i, 0, strlen(cad) - 1, cad[i] = tolower(cad[i]));
    return cad;
}
static inline wchar_t * wcadMinus(wchar_t * wcad)
{
    FOR_RANGO(i, 0, wcslen(wcad) - 1, wcad[i] = towlower(wcad[i]));
    return wcad;
}

static inline char * cadReversa(char *cad)
{
    size_t largo = strlen(cad);
    FOR_RANGO(i, 0, largo / 2 - 1, INTERCAMBIAR(cad[i], cad[largo - i - 1]));
    return cad;
}

static inline char * cadReversaLargo(char *cad, size_t largo)
{
    FOR_RANGO(i, 0, largo / 2 - 1, INTERCAMBIAR(cad[i], cad[largo - i - 1]));
    return cad;
}

static inline wchar_t * wcadReversa(wchar_t *wcad)
{
    size_t largo = wcslen(wcad);
    FOR_RANGO(i, 0, largo / 2 - 1, INTERCAMBIAR(wcad[i], wcad[largo - i - 1]));
    return wcad;
}

static inline wchar_t * wcadReversaLargo(wchar_t *wcad, size_t largo)
{
    FOR_RANGO(i, 0, largo / 2 - 1, INTERCAMBIAR(wcad[i], wcad[largo - i - 1]));
    return wcad;
}


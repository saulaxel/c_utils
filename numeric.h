#include <limits.h>

#define bits_signed(type) (sizeof(type) * CHAR_BIT - 1)
#define bits_unsigned(type) (sizeof(type) * CHAR_BIT)

// Función para obtener el punto medio que no debe causar desbordamiento de
// entero
#define FUNCION_MITAD(nombre, tipo_args, tipo_unsigned_aux)    \
    static inline tipo_args nombre(tipo_args x, tipo_args y) { \
        int signo = 1;                                         \
        tipo_unsigned_aux small = x;                           \
        tipo_unsigned_aux big = y;                             \
        if (x > y) {                                           \
            signo = -1;                                        \
            small = y;                                         \
            big = x;                                           \
        }                                                      \
        return x + signo * (tipo_args)((big - small) / 2);     \
    }

FUNCION_MITAD(mitad_int, int, unsigned)
FUNCION_MITAD(mitad_uint, unsigned, unsigned)
FUNCION_MITAD(mitad_long, long, unsigned long)
FUNCION_MITAD(mitad_ulong, unsigned long, unsigned long)
FUNCION_MITAD(mitad_llong, long long, unsigned long long)
FUNCION_MITAD(mitad_ullong, unsigned long long, unsigned long long)

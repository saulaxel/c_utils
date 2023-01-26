#ifndef GENERIC_CMP_H
#define GENERIC_CMP_H

// GENERIC_WRAP_CMP puede tomar una función de comparación que reciba punteros a un
// objeto, y rodearla de una función de comparación genérica
#define GENERIC_WRAP_CMP(type, fun, name)                      \
    static inline int name(const void * pa, const void * pb) { \
        return fun(*(type *)pa, *(type *)pb);                  \
    }

// GENERIC_NUMERIC_CMP puede generar una función de comparación genérica de tipos que
// pueden usar los operadores de comparación > y <
#define GENERIC_NUMERIC_CMP(type, name)                        \
    static inline int name(const void * pa, const void * pb) { \
        type a = *(type *)pa;                                  \
        type b = *(type *)pb;                                  \
        return (a > b) ? 1 : (b > a) ? -1 : 0;                 \
    }
// return a - b puede causar desbordamiento, por lo que se evita

#endif // GENERIC_CMP_H

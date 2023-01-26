#ifndef ARRAY_SORTING_H
#define ARRAY_SORTING_H

#include <stdlib.h>
#include <search.h>
#include <stddef.h>

#if __GNUC__
#define MAYBE_UNUSED __attribute__((unused))
#else
#define MAYBE_UNUSED
#endif

#define ARRAY_SORT_FUNCTION(type, name, cmp_function)        \
    static inline void name(size_t n, type array[/* n */]) { \
        qsort(array, n, sizeof(*array), cmp_function);       \
    }

#define ARRAY_LSEARCH_FUNCTION(type, name, cmp_function)                               \
    static inline long name(size_t n, type array[/* n */], type buscado) {             \
        char * pos = (char *)lfind(&buscado, array, &n, sizeof(*array), cmp_function); \
        if (!pos)                                                                      \
            return -1;                                                                 \
                                                                                       \
        ptrdiff_t diff = pos - (char *)array;                                          \
        return diff / sizeof(*array);                                                  \
    }

#define ARRAY_BSEARCH_FUNCTION(type, name, cmp_function)                        \
    static inline long name(size_t n, type array[/* n */], type buscado) {      \
        return binary_search(&buscado, array, n, sizeof(*array), cmp_function); \
    }

#define ARRAY_FUNCTIONS(type, prefix, cmp_function)                 \
    ARRAY_SORT_FUNCTION(type, prefix ## _sort, cmp_function);       \
    ARRAY_LSEARCH_FUNCTION(type, prefix ## _lsearch, cmp_function); \
    ARRAY_BSEARCH_FUNCTION(type, prefix ## _bsearch, cmp_function);

MAYBE_UNUSED static long
binary_search(const void * buscado, const void * array,
        size_t arr_len, size_t member_size,
        int cmp(const void *, const void *)) {
    // Si el elemento ya existe en el arreglo, se regresa una posición de
    // inserción positiva. Si el elemento no está en el arreglo, se regresa la
    // -(posición_en_que_debería_insertarse + 1)
    long mid = 0;
    long l = 0;
    long r = arr_len - 1;
    int compare = -1;
    const char * base = (const char *)array;

    while (l <= r) {
        mid = l + (r - l) / 2; // Esta forma de calcular el punto medio
                               // previene desbordamiento de entero

        compare = cmp(buscado, base + mid * member_size);
        if (compare == 0) {
            return mid;
        }
        else if (compare > 0) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    int insert_position = 0;

    if (compare > 0) {
        insert_position = mid + 1;
    } else {
        insert_position = mid;
    }

    return -(insert_position + 1);
}

#endif // ARRAY_SORTING_H

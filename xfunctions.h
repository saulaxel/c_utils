#ifndef XFUNCTIONS_H
#define XFUNCTIONS_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define XFUNCTIONS_CHECK_OR_DIE(condition) \
    if (!(condition)) {                    \
        exit(EXIT_FAILURE);                \
    }

static inline void * xmalloc(size_t nbytes)
{
    void * result = malloc(nbytes);
    XFUNCTIONS_CHECK_OR_DIE(result != NULL);
    return result;
}

static inline void * nmalloc(size_t nitems, size_t size)
{
    size_t producto = size * nitems;

    if (producto / size != nitems) {
        errno = ENOMEM;
        return NULL;
    }

    return malloc(producto);
}

static inline void * xnmalloc(size_t nitems, size_t size)
{
    void * result = nmalloc(nitems, size);
    XFUNCTIONS_CHECK_OR_DIE(result != NULL);
    return result;
}

static inline void * xcalloc(size_t nitems, size_t size)
{
    void * result = calloc(nitems, size);
    XFUNCTIONS_CHECK_OR_DIE(result != NULL);
    return result;
}

static inline void * xrealloc(void * prev_dir, size_t nbytes)
{
    void *result = realloc(prev_dir, nbytes);
    XFUNCTIONS_CHECK_OR_DIE(result != NULL);
    return result;
}

static inline FILE * xfopen(const char *fname, const char *mode)
{
    FILE * f = fopen(fname, mode);
    XFUNCTIONS_CHECK_OR_DIE(f != NULL);
    return f;
}

#define XNOTNULL_OR_ELSE(expression, code_if_null) ({ \
            void * aux_ = (expression);               \
            if (! aux_) {                             \
                code_if_null;                         \
            }                                         \
            aux_;                                     \
        })

#undef XFUNCTIONS_CHECK_OR_DIE

#endif // XFUNCTIONS_H

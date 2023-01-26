#include <stdbool.h>
#include "xfunctions.h"

#define NUEVO_ARR(n, tipo, inicializado_cero) \
    (tipo *)((inicializado_cero) ? calloc : nmalloc)(n, sizeof(tipo))
#define NUEVO(tipo) NUEVO_ARR(1, tipo, true)
#define REDIM_ARR(viejo, n, tipo) \
    (tipo *)(realloc(viejo, n * sizeof(tipo)))

#define NUEVO_PRIMITIVO(tipo, val)                                           \
    ({                                                                       \
        tipo * var_tmp = NUEVO_ARR(1, tipo, false);                          \
        *var_tmp         = (val);                                            \
        var_tmp;                                                             \
    })

#define NUEVA_STRUCT(tipo, ...)                                              \
    ({                                                                       \
        tipo * var_tmp = NUEVO_ARR(1, tipo, false);                          \
        *var_tmp         = (tipo){ __VA_ARGS__ };                            \
        var_tmp;                                                             \
    })

#define XNUEVO_ARR(n, tipo, inicializado_cero) \
    (tipo *)((inicializado_cero) ? xcalloc : xnmalloc)(n, sizeof(tipo))
#define XNUEVO(tipo) XNUEVO_ARR(1, tipo, true)

#define XNUEVO_PRIMITIVO(tipo, val)                                          \
    ({                                                                       \
        tipo * var_tmp = XNUEVO_ARR(1, tipo, false);                         \
        *var_tmp         = (val);                                            \
        var_tmp;                                                             \
    })

#define XNUEVA_STRUCT(tipo, ...)                                             \
    ({                                                                       \
        tipo * var_tmp = XNUEVO_ARR(1, tipo, false);                         \
        *var_tmp         = (tipo){ __VA_ARGS__ };                            \
        var_tmp;                                                             \
    })

#define XREDIM_ARR(viejo, n, tipo) \
    (tipo *)(xrealloc(viejo, n * sizeof(tipo)))

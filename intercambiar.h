
#define INTERCAMBIAR(var1, var2)   \
    do {                           \
        typeof(var1) aux = (var1); \
        (var1)           = (var2); \
        (var2)           = aux;    \
    } while (0)

#include <stdbool.h>

static inline bool es_par(int n) {
    return n % 2 == 0;
}

static inline bool ues_par(unsigned n) {
    return n % 2 == 0;
}


static inline bool es_impar(int n) {
    return n % 2 != 0;
}

static inline bool ues_impar(unsigned n) {
    return n % 2 != 0;
}


static inline bool es_divisible(int a, int divisor) {
    return a % divisor == 0;
}

static inline bool ues_divisible(unsigned a, unsigned divisor) {
    return a % divisor == 0;
}


static inline int maximo_comun_divisor(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

static inline unsigned umaximo_comun_divisor(unsigned a, unsigned b) {
    unsigned temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


static inline int minimo_comun_multiplo(int a, int b) {
    return (a * b) / maximo_comun_divisor(a, b);
}

static inline unsigned uminimo_comun_multiplo(unsigned a, unsigned b) {
    return (a * b) / maximo_comun_divisor(a, b);
}

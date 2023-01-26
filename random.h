#include <time.h>
#include <stdlib.h>

static inline void seed_rand(void) {
    srand((unsigned int)time(NULL));
}

static inline int rand_range(int min, int max) {
    return min + rand() % (1 + max - min);
}

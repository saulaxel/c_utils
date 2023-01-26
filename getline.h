#include <stdio.h>

static inline void gets(char * str, size_t count)
{
    fgets(str, count, stdin);
}

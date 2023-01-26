#include <assert.h>
#include "intercambiar.h"

int main(void)
{
    int a = 1, b = 2;

    INTERCAMBIAR(a, b);
    assert(a == 2 && b == 1);
}

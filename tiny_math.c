#include <stdio.h>
#include <assert.h>
#include "tiny_math.h"

int gcd(int a, int b)
{
    assert(a > 0 && b > 0);

    if (a < b)
    {
        return gcd(b, a);
    }
    int m = a % b;
    
#ifdef DEBUG
    printf("%d = %d*%d + %d\n", a, b, a/b, m);
#endif

    if (m == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, m);
    }
}

int lcm(int a, int b)
{
    return a*b / gcd(a, b);
}

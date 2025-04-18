#include <stdio.h>
#include <stdlib.h>
#include "tiny_math.h"

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        return -1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = gcd(a, b);
    printf("gcd(%d, %d) = %d\n", a, b, c);

    return 0;
}

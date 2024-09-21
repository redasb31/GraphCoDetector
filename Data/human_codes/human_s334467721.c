#include <stdio.h>

int main(void)
{
    int z, zzz, x, y, max, t;

    while(scanf("%d", &z), z)
    {
        max = 0, zzz = z * z * z;

        for(x = 1; x < z - 1; x++)
            for(y = 1; y <= x; y++)
            {
                t = x * x * x + y * y * y;
                if(t > zzz) break;
                else if(t > max) max = t;
            }
        printf("%d\n", zzz - max);
    }

    return 0;
}
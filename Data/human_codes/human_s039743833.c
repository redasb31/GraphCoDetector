#include <stdio.h>

int main(void)
{
    int n, p[100000], count = 0;
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i += 2)
    {
        if (p[i] == i + 1 || p[i + 1] == i + 2)
        {
            count++;
        }
    }

    printf("%d", count);
    return (0);
}
#include<stdio.h>
#include <stdlib.h>

int main(void)
{
    int D;
    int T;
    int S;

    D = scanf("%d");
    T = scanf("%d");
    S = scanf("%d");

    if (D / S < T)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}


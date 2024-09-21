#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    printf("a=");
    scanf("%d", &a);
    b = a + pow(a,2) + pow(a,3);
    printf("%d", b);
    return 0;
}
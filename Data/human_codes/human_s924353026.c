#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a1, a2, a3;
    scanf("%d %d %d", &a1, &a2, &a3);

    int max=a1;
    int min=a1;
    if(max < a2){max=a2;}
    if(max < a3){max=a3;}
    if(min > a2){min=a2;}
    if(min > a3){min=a3;}
    max -= min;

    printf("%d\n", max);


    return 0;
}


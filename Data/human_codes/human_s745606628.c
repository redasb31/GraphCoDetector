#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(abs(a-b)==abs(b-c))
        printf("Yes");
    else
        printf("No");
return 1;
}

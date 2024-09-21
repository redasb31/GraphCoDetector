#include<stdio.h>
int main ()
{

    int w,a,b,t;
    scanf("%d%d%d",&w,&a,&b);
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    a=a+w;
    if(a>b)
        printf("0\n");
    else
        printf("%d\n",b-a);
    return 0;
}

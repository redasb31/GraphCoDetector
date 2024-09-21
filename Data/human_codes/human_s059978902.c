#include <stdio.h>
int main()
{
    int a, b, c, t;
    scanf("%d %d %d",&a,&b,&c);
    if(a<=10000 && a>=0 && b<=10000 && b>=0 && c<=10000 && c>=0)
    {
        if(a>b)
        {
        int t = a;
             a = b;
             b = t;
        }

        if(b>c)
        {
        int t = b;
             b = c;
             c = t;
        }

        if(a>b)
        {
        int t = a;
             a = b;
             b = t;
        }
        printf("%d\n",a+b);

    }
        return 0;
}

#include<stdio.h>
int main()
{
    int a,b,c,x=0;
    scanf("%d %d %d",&a,&b,&c);
    while(1)
    {
        if(a<b && c<b || a==c && a!=b && b!=c && a<b && c<b)
        {
            a=a+1;
            c=c+1;
            x++;
        }
        else if(a<c && b<c || a==b && a!=c && b!=c && a<c && b<c)
        {
            a=a+1;
            b=b+1;
            x++;
        }
        else if(b<a && c<a || b==c && b!=a && c!=a && b<a && c<a)
        {
            b=b+1;
            c=c+1;
            x++;
        }
        if(a<b && a<c)
        {
            a=a+2;
            x++;
        }
        else if(b<a && b<c)
        {
           b=b+2;
           x++;
        }
        else if(c<a && c<b)
        {
            c=c+2;
            x++;
        }
        if(a==b && b==c && c==a)
        {
            break;
        }
    }
    printf("%d\n",x);

    return 0;
}

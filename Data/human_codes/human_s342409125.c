#include<stdio.h>
int main()
{
    long long int a,b;
    char c;
    scanf("%lld %c %lld", &a,&c,&b);
    if(c=='+')
    {
        printf("%lld", a+b);
    }
    else if(c=='-')
    {
        printf("%lld", a-b);
    }
    return 0;
}

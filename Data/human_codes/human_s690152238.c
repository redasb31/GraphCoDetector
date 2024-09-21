#include<stdio.h>
int main()
{
    int a,b,r,rem;
    scanf("%d%d",&a,&b);
    rem=b/a;
    if(b%a!=0)
    r=rem+1;
    else
    r=rem;
    printf("%d",r);
    return 0;
}
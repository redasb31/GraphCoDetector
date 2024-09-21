#include<stdio.h>
int sum(int a)
{
    int b,s=0;
    while(a!=0)
    {
       b=a%10;
       a=a/10;
       s=s+b;
       if(a==0)
       {
           break;
       }
    }
    return s;
}
int main()
{
    int n,a,b,i,cnt=0;
    scanf("%d %d %d",&n,&a,&b);
    for(i=1;i<=n;i++)
    {
        if(sum(i)>=a && sum(i)<=b)
        {
            cnt=cnt+i;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

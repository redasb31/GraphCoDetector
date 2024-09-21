#include<stdio.h>
int main()
{
    int n,a,b,i,c[10000],d[10000],sum[10000],j,fsum=0,h[10000],k;
    scanf("%d %d %d",&n,&a,&b);
    for(i=0; i<n; i++)
    {
        sum[i]=0;
    }
    for(i=0; i<n; i++)
    {
        c[i]=i+1;
    }
    for(i=0; i<n; i++)
    {
        d[i]=c[i];
    }
    for(i=0; i<n; i++)
    {
        while(d[i]!=0)
        {
            sum[i]=sum[i]+d[i]%10;
            d[i]=d[i]/10;
        }
    }
    for(i=0; i<n; i++)
    {
        if(sum[i]>=a && sum[i]<=b)
        {
            fsum=fsum+c[i];
        }
    }
    printf("%d\n",fsum);
    return 0;
}

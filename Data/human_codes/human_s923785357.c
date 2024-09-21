#include <stdio.h>
#include <stdlib.h>
int rank(const long long*p1,const long long*p2)
{
    return *p1-*p2;
}
long long b[199999000];
int main()
{
    int n,a[200001],i,j,r=0,m;
    long long k;
    scanf("%d%lld",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
            b[r++]=(long long)(a[i])*a[j];
    }
    m=n*(n-1)/2;
    qsort(b,m,sizeof(long long),rank);
    printf("%lld",b[k-1]);
    return 0;
}

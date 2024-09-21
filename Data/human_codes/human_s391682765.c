#include<stdio.h>
#include<math.h>
int main(void)
{
	long long int a[200000],x,y=0,dim;
	int n,i,t;
	scanf("%d",&n);
	scanf("%lld",&a[0]);
	x=a[0];
	for(i=1;i<n;i++)
	{
		scanf("%lld",&a[i]);
		y+=a[i];
	}
	dim=abs(x-y);
	for(t=1;t<n-1;t++)
	{
		x+=a[t];
	    y-=a[t];
        if(abs(x-y)<dim)
        {
        	dim=abs(x-y);
		}
	}
	printf("%lld",dim);
    return 0;
}
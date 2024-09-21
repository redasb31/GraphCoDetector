#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int N,i,j;
	scanf("%d",&N);
	long long int a[N],x,y,sum=2000000000,sum1,sum2;
	
	for(i=0;i<N;i++)
	  scanf("%lld",&a[i]);
	
	for(i=1;i<N;i++)
	{
		x=0;y=0;
		for(j=0;j<i;j++)
		  x=x+a[j];
		for(j=N-1;j>=i;j--)
		  y=y+a[j];
		sum2=x-y;
		sum1=llabs(sum2);
		if(sum1<sum)
		  sum=sum1;
	}
	
	printf("%lld",sum);
	
	return 0;	
}
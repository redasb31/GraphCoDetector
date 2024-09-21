#include<stdio.h>

int mod=1000000007;
int main()
{
	int N,a[10001],b[100001],i,j,k=0,sum=2;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		b[i]=0;
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++)
		b[a[i]]++;
	if(N%2!=0)
	{
		if(b[0]!=1)
				k=1;
			for(i=2;i<N;i+=2)
				if(b[i]!=2)
					k=1;
	}
	else
	{
		for(i=1;i<N;i+=2)
			if(b[i]!=2)
				k=1;
	}
	if(N%2)
	{
		if(k)
			printf("0\n");
		else
		{
			for(j=1;j<((N-1)/2);j++)
				sum=(sum*2)%mod;
			printf("%d\n",sum%mod);
		}
	}
	else
	{
		if(k)
			printf("0\n");
		else
		{
			for(j=1;j<(N/2);j++)
				sum=(sum*2)%mod;
			printf("%d\n",sum%mod);
		}
			
	}
	return 0;
}
#include<stdio.h>
int main()
{
	long n,a[100000],i,fhelp,thelp;
	long long help;
	while(~scanf("%ld",&n))
	{
		for(i=0,fhelp=thelp=0;i<n;i++) 
		{
			scanf("%ld",&a[i]);
			if(a[i]%4==0) fhelp++;
			else if(a[i]%2==0) thelp++;
		}
		if(thelp>1) help=fhelp*3+thelp-1;
		else help=fhelp*3;
		if(thelp==n) help=n;
		printf(help>=n?"Yes\n":"No\n");
	}
} 
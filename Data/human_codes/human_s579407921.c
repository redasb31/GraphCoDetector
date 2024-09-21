#include <stdio.h>

main()
{
	long a,v,b,w,t;
	int i;
	
	
	scanf("%ld",&a);
	scanf("%ld",&v);
	scanf("%ld",&b);
	scanf("%ld",&w);
	scanf("%ld",&t);
		
	if(a<b)
	{
		for(i=0;i<t;i++)
		{
			a+=v;
			b+=w;
			if(b>=1000000000)
			{
				b-=w;
			}
		}
		
		
		if(a>=b)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
	}
	else
	{
		for(i=0;i<t;i++)
		{
			a-=v;
			b-=w;
			if(b<=-1000000000)
			{
				b+=w;
			}
		}
		
		if(a<=b)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
	}	
}
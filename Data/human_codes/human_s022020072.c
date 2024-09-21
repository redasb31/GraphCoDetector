#include<stdio.h>
int main ()
{
	int a,b,c,d,e,i,j,x,y;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	i=a/b;
	j=a%b;
	if(j>0)
	{
		i=i+1;
	}
	x=a/d;
	y=a%d;
	if(y>0)
	{
		x=x+1;
	}
	i=i*c;
	x=x*e;
	if(i<x)
	{
		printf("%d\n",i);
	}
	if(i>x)
	{
		printf("%d\n",x);
	}
	if(i==x)
	{
		printf("%d\n",i);
	}
	
	
	
	return 0;
}

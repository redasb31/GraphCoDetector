#include<stdio.h>
int main()
{
	int n,m,x,i,d;
	int fro,bac;
	while(scanf("%d%d%d",&n,&m,&x)==3)
	{
		fro=0;
		bac=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&d);
			if(d<x)
			fro++;
			else
			bac++;
		}
		int res=(fro<bac?fro:bac);
		printf("%d\n",res);
	}
	return 0;
}
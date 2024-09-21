#include<stdio.h>
#include<string.h>
int N,K,M,f[10000],n,i,p;
int main()
{
	for(;scanf("%d%d%d",&N,&K,&M),N;)
	{
		memset(f,0,sizeof(f));
		for(n=N,p=M-1,f[p]=1;n>1;n--)
		{
			for(i=0;;p=(p+1)%N)
				if(!f[p]&&++i>=K)
					break;
			f[p]=1;
		}
		printf("%d\n",p+1);
	}
	return 0;
}
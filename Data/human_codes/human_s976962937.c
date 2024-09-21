#include<stdio.h>
int n,m,map[20][20],mark[20],sum;
void dfs(int x)
{
	int i,j=0;
	for(i=1;i<=n;i++)
	{
		if(mark[i]==1)
		j++;
	}
	if(j==n)
	{
		sum++;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(!mark[i]&&map[x][i]==1)
		{
			mark[i]=1;
			dfs(i);
			mark[i]=0;
		}
	}
	return;
}
int main(void)
{
	int a,b,i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(mark,0,sizeof(mark));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a][b]=map[b][a]=1;
	}
	mark[1]=1;
	sum=0;
	for(i=2;i<=n;i++)
	{
		if(!mark[i]&&map[1][i]==1)
		{
			mark[i]=1;
			dfs(i);
			mark[i]=0;
		}
	}
	printf("%d\n",sum);
	}
	return 0;
}
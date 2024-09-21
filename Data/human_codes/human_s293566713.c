#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int ch[2][1<<22],id[22][1<<21],cnt,a[22][1<<22],siz[22],c[22][1<<22],num[22][1<<22],ans[22],N,K;
inline void get()
{
	id[0][0]=++cnt;
	ch[0][id[0][0]]=ch[1][id[0][0]]=-1;
	for(int i=1;i<=20;i++)
	{
		int t=(1<<i),k=(t>>1);
		for(int s=0;s<t;s++)
		{
			id[i][s]=++cnt;
			int p=(s&k),q=(p?1:0);
			ch[q][id[i][s]]=id[i-1][s^p];
			ch[!q][id[i][s]]=ch[!q][id[i-1][s^p]];
		}
	}
}
inline void dfs(int d,int s)
{
	if(ans[d]==-1)ans[d]=s;
	for(int p=0;p<=1;p++)
	{
		int tot=0;
		for(int i=0;i<siz[d];i++)
		{
			int to=ch[p][a[d][i]];
			if(to==-1)continue;
			if(num[d+1][to]==-1)
			{
				num[d+1][a[d+1][siz[d+1]]=to]=siz[d+1];
				siz[d+1]++;
			}
			tot+=c[d][i];
			c[d+1][num[d+1][to]]+=c[d][i];
		}
		if(tot>=K)dfs(d+1,(s<<1)|p);
		for(int i=0;i<siz[d+1];i++)
		{
			num[d+1][a[d+1][i]]=-1;
			c[d+1][i]=0;
		}
		siz[d+1]=0;
	}
}
char s[1<<21];
int main()
{
	N=read();
	K=read();
	get();
	for(int i=0;i<=N;i++)for(int j=0;j<cnt;j++)num[i][j]=-1;
	for(int i=0;i<=N;i++)
	{
		scanf("%s",s);
		int t=(1<<i);
		for(int j=0;j<t;j++)if(s[j]=='1')
		{
			num[0][a[0][siz[0]]=id[i][j]]=siz[0];
			c[0][num[0][id[i][j]]]++;
			siz[0]++;
		}
		ans[i]=-1;
	}
	dfs(0,0);
	for(int i=N;i>=0;i--)if(ans[i]!=-1)
	{
		for(int j=i-1;j>=0;j--)putchar(((ans[i]>>j)&1)+'0');
		puts("");
		return 0;
	}
	return 0;
}
/*
*/
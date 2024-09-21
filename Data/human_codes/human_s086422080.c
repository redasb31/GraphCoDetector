#define D 1000000007
#define M 100002
char s[M],t[M];
int  N,i,c[128];
int main()
{
	scanf("%d%s%s",&N,s,t);
	for(c[s[0]]=1,N--,i=1;i<N;i++){
		c[s[i]]+=c[t[i]];
		c[s[i]]-=c[s[i]]>=D?D:0;
	}
	printf("%d\n", c[t[N]]);
}

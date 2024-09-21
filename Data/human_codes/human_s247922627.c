#include<stdio.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define add(x)(x=(x+t)%MOD)

int dp[210][1100];
int N,K,MOD;
int main(){
	scanf("%d%d%d",&N,&K,&MOD);
	dp[0][0]=1;
	rep(n,0,2*N)rep(k,0,(1<<K)-1){
		int t=dp[n][k];
		if(k<1<<(K-1))add(dp[n+1][2*k+1]);
		if(k)add(dp[n+1][(k^(1<<(31-__builtin_clz(k))))*2]);
	}
	printf("%d\n",(dp[2*N][0]+(N==K))%MOD);
}

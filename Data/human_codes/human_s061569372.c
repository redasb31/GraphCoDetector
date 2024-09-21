#include<stdio.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define chmax(p,q)(p=max(p,q))

int k[210];
int h[210][21];
int s[210][21];
double x[210][210];
double dp[210][210];

int main(){
	int n,v;
	scanf("%d%d",&n,&v);
	rep(i,0,n){
		scanf("%d",k+i);
		rep(j,0,k[i])scanf("%d%d",s[i]+j,h[i]+j);
	}
	
	rep(i,0,n){
		int pos=0,hh=0;
		for(int j=1;j<=200&&pos<k[i];j++){
			x[i][j]=x[i][j-1]+1.0/s[i][pos];
			if(++hh==h[i][pos]*s[i][pos])pos++,hh=0;
		}
	}
	
	rep(i,0,n)rep(j,0,v+1)rep(d,0,v-j+1)chmax(dp[i+1][j+d],dp[i][j]+x[i][d]);
	printf("%.9f\n",dp[n][v]);
}

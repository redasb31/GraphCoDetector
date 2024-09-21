#include<stdio.h>
#include<stdlib.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

double dp[150][220];//√2倍まで
int main(){
	int n;
	scanf("%d",&n);
	rep(j,0,220)dp[0][j]=1e9;
	dp[0][1]=0;
	rep(i,0,n){
		int t;
		scanf("%d",&t);
		rep(j,1,220){
			double temp=1e9;
			rep(k,1,220){
				if(j<=t^k<=t){
					int a=abs(t-j);
					int b=abs(t-k);
					temp=min(temp,dp[i][k]+(a*a+b*b)/2.0/(a+b));
				}else temp=min(temp,dp[i][k]+abs(t+t-j-k)/2.0);
			}
			dp[i+1][j]=temp;
		}
	}
	double ans=1e9;
	rep(j,1,220)ans=min(ans,dp[n][j]);
	printf("%.9f\n",ans);
}

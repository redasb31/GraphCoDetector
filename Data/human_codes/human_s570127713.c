#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int main(){
	int n,w,i,j;
	long wv[2][101];
	long long dp[101][100002]={{0}},ans=0;
	scanf("%d%d",&n,&w);
	for(i=0;i<n;i++){
		scanf("%ld%ld",&wv[0][i],&wv[1][i]);
//		dp[i][wv[0][i]]=wv[1][i];
	}
	for(i=0;i<=w;i++){
		for(j=0;j<n;j++){
			if(wv[0][j]<=i){
				dp[j][i]=max(dp[j-1][i-wv[0][j]]+wv[1][j],dp[j-1][i]);
			}
		}
	}
	for(i=0;i<n;i++)ans=max(ans,dp[i][w]);
	printf("%lld\n",ans);
	return 0;
}
#include<stdio.h>
long long int mod=1000000007;
long long int solve(int N,int M){
	static long long int dp[3001][3001]={0};
	long long int i,j,ans=0;
	if(N==0){return 0;}
	for(i=0;i<=N;i++){
		dp[0][i]=1;
	}
	for(j=1;j<=M;j++){
		i=0;
		dp[j][i]=dp[j-1][i]+dp[j-1][i+1];dp[j][i]%=mod;
		for(i=1;i<N;i++){
			dp[j][i]=dp[j-1][i-1]+dp[j-1][i]*2+dp[j-1][i+1];dp[j][i]%=mod;
		}
		dp[j][i]=dp[j-1][i-1]+dp[j-1][i];dp[j][i]%=mod;
	}
	for(i=0;i<=N;i++){
		ans+=dp[M][i];ans%=mod;
	}
	return ans;
}
int main(void){
	int N,M,it;
	scanf("%d %d",&N,&M);
	it=solve(N,M)-solve(N-1,M);
	if(it<0){it+=mod;}
	printf("%d\n",it);
	return 0;
}
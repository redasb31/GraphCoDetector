#include <stdio.h>
int main(){
	int n,m,i,a,dp[100002]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){scanf("%d",&a);dp[a]=-1;}
	dp[0]=1;
	dp[1]=(dp[1]==-1?-1:1);
	for(i=2;i<=n;i++){
		if(dp[i-1]==-1&&dp[i-2]==-1){printf("-1");return 0;}
		else if(dp[i]<0)continue;
		else if(dp[i-1]==-1)dp[i]=dp[i-2];
		else if(dp[i-2]==-1)dp[i]=dp[i-1];
		else dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=1000000007;
	}
	printf("%d", dp[n]);
}
#include <stdio.h>
#define llinf 922337203685477
long long llmin(long long a,long long b){
    return a<b?a:b;
}
int main(){
    long long n,W;
    scanf("%lld%lld",&n,&W);
    long long dp[n+1][100001];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=100000;j++)
        dp[i][j]=llinf;
    }
    dp[0][0]=0;
    long long v[n],w[n];
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&w[i],&v[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<100000;j++){
            if(j>=v[i]){
                dp[i+1][j]=llmin(dp[i][j-v[i]]+w[i],dp[i][j]);
            }
            dp[i+1][j]=llmin(dp[i][j],dp[i+1][j]);
        }
    }
    for(int i=100000;i>=0;i--){
        if(dp[n][i]<=W){
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
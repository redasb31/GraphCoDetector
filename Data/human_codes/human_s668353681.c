#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
int N,A;
int x[51];
ll dp[51][51][2501];
int max;

void solve(){
  int i,j,k;
  ll ans = 0;
  
  dp[0][0][0] = 1;
  for(i = 0; i <= N; i++){
    for(j = 0; j <= N; j++){
      for(k = 0; k <= N*max; k++){
	if(k < x[i] && i >= 1)dp[i][j][k] = dp[i-1][j][k];
      else if (i >= 1 && j >= 1 && k >= x[i]) dp[i][j][k] = dp[i-1][j][k]+dp[i-1][j-1][k-x[i]];
      else if(i+j+k != 0)dp[i][j][k] = 0;
      }
    }
  }
  for(i = 1; i <= N ; i++){
    ans += dp[N][i][i*A];
  }
  printf("%lld\n",ans);
}
#include<stdio.h>
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, t, s, a[3002], b[3002];
int dp[3002][3002];
int i, j, ans;

int main(){
  scanf("%d%d%d", &n, &t, &s);
  for(i = 0;i < n;i++){
    scanf("%d%d", a + i, b + i);
  }
  for(i = 0;i < n;i++){
    for(j = 0;j <= t;j++){
      if(j + b[i] <= t){
	if(j < s && s < j + b[i])continue;
	dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j] + a[i]);
      }
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
    }
  }
  ans = 0;
  for(i = 0;i <= t;i++){
    ans = max(ans, dp[n][i]);
  }
  printf("%d\n", ans);
  return 0;
}
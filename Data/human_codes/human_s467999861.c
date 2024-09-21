#include<stdio.h>
#include<string.h>

int i, j, k, n, x, m, menu[30], dp[1000000],prime[1000001], ans;
int main(){
  for(i = 2;i <= 1000;i++){
    if(prime[i] == 1)continue;
    for(j = i * i;j < 1000000;j += i){
      prime[j] = 1;
    }
  }
  while(1){
    scanf("%d%d", &n, &x);
    if(n == 0 && x == 0)return 0;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(i = 0;i < n;i++){
      scanf("%d", menu + i);
    }
    ans = 0;
    for(i = 1;i <= x;i++){
      for(j = 0;j < n;j++){
	if(i - menu[j] >= 0 && dp[i - menu[j]] == 1)
	  dp[i] = 1;
      }
      if(dp[i] == 1 && prime[i] == 0){
	ans = i;
      }
    }
    if(ans == 0)
      puts("NA");
    else
      printf("%d\n", ans);
  }
}
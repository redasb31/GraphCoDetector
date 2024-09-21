#include<stdio.h>
#include<stdlib.h>

int less(const void* a, const void* b){
  return *(int*)a - *(int*)b;
}

int is_no_need(int i, const int* a, int K, int N){
  int dp[K];
  for(int k = 0; k < K; k++) dp[k] = 0;
  
  for(int j = 1; j <= N; j++){
    if(j == i) continue;
    
    for(int k = K - 1; k >= a[j]; k--){
      if(dp[k - a[j]] + a[j] > dp[k])
        dp[k] = dp[k - a[j]] + a[j];
    }
  }
  
  return dp[K - 1] + a[i] < K;
}

int count_no_need(const int* a, int K, int N){
  //不必要でないカードのうち, 書かれた数が最小であるもの
  int need = N + 1;
  //不必要であるカードのうち, 書かれた数が最大であるもの
  int no_need = 0;
  
  while(need - no_need > 1){
    int i = (need + no_need) / 2;
    
    if(is_no_need(i, a, K, N)) no_need = i;
    else need = i;
  }
  
  return no_need;
}

int main(){
  int N, K;
  scanf(" %d %d ", &N, &K);
  
  int a[N + 1];
  a[0] = 0;
  for(int i = 1; i <= N; i++) scanf(" %d ", a + i);
  qsort(a, N + 1, sizeof(int), less);
  
  printf("%d\n", count_no_need(a, K, N));
  
  return 0;
}

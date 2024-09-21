#include<stdio.h>

const int mod = 1e9 + 7;

int main(){
  int N, M; scanf("%d%d", &N, &M);
  int S[N], T[M];
  for(int i = 0; i < N; i++) scanf("%d", S + i);
  for(int j = 0; j < M; j++) scanf("%d", T + j);
  
  long long num[N + 1][M + 1];
  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= M; j++){
      if(i == 0 || j == 0) num[i][j] = 1;
      else num[i][j] = 0;
    }
  }
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      num[i + 1][j + 1] += num[i + 1][j] + num[i][j + 1] % mod;
      if(S[i] != T[j])
        num[i + 1][j + 1] -= num[i][j];
      num[i + 1][j + 1] %= mod;
    }
  }
  
  printf("%lld\n", num[N][M]);
  
  return 0;
}
#include <stdio.h>

int main(void){
  int N,K;
  scanf("%d%d",&N,&K);

  if(N-K < 2){
    printf("-1\n");
    return 0;
  }

  int M = 0;
  for (int i = 1; i <= K+1; i++) M++;
  for (int i = K+1; i <= N; i++) {
    for (int j = 1; j < K; j++) {
      M++;
    }
  }
  printf("%d\n",M);
  for (int i = 1; i <= K+1; i++) {
    printf("%d %d\n",i,i+1);
  }
  for (int i = K+1; i <= N; i++) {
    for (int j = 1; j < K; j++) {
      printf("%d %d\n",i,j);
    }
  }

  return 0;
}
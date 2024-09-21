#include <stdio.h>

int A[100000];

int Abs(int x){
  if(x < 0) return -x;
  else return x;
}

void Do(int N){
  int i, c, C, m, n;
  long long B;
  c = 0;
  C = 0;
  m = 1e9;
  n = -1;
  for(i = 0;i < N;i++){
    scanf("%d", &A[i]);
    if(A[i] == 0) c = 1;
    if(c == 0 && A[i] < 0) C++;
    if(m > Abs(A[i])){
      m = Abs(A[i]);
      n = i;
    }
  }
  B = 0;
  if(c == 0 && C % 2 == 1){
    for(i = 0;i < N;i++){
      if(i == n) B -= Abs(A[i]);
      else B += Abs(A[i]);
    }
  }else for(i = 0;i < N;i++) B += Abs(A[i]);
  printf("%lld\n", B);
}

int main(void){
  int N;
  scanf("%d", &N);
  Do(N);
  return 0;
}

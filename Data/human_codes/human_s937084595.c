#include<stdio.h>
#include<math.h>


int main(void)
{
  long long int N;
  scanf("%lld", &N);
  long long int a[N], b[N];
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%lld", &b[i]);
  }
  
  //２進数表記
  int t[N*N][29];
  for (long int i = 0; i < N; i++) {
    for (long int j = 0; j < N; j++) {
      long long int tmp = a[i] + b[i];
      for (int l = 0; l < 29; l++) {
        t[i*j][l] = tmp / pow(2,29-l);
        tmp = tmp % pow(2,29-l);
      }
    }
  }
  
  int u[29];
  
  for (int l = 0; l < 29; l++) {
    u[l] = 0;
    for (long long int i = 0; i < N*N; i++) {
      u[l] += t[i][l];
    }
    if (u[l] % 2 == 0) u[l] = 0;
    else u[l] = 1;
  }
  
  long int ans = 0;
  for (int i = 0; i < 29; i++) {
    ans = u[i]*pow(2, 29-i);
  }
  printf("%ld", ans);
  
  return 0;
}







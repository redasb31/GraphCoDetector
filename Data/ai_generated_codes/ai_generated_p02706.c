#include <stdio.h>

int main() {
  // N: Number of days of summer vacation
  int N;
  // M: Number of summer assignments
  int M;
  // A_i: Days required to complete the i-th assignment
  int A[10000];
  // Read input values
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &A[i]);
  }
  // Calculate the total days required for all assignments
  int total_days = 0;
  for (int i = 0; i < M; i++) {
    total_days += A[i];
  }
  // Check if all assignments can be completed within the vacation
  if (total_days > N) {
    printf("-1\n");
    return 0;
  }
  // Calculate the maximum number of days Takahashi can hang out
  int hang_out_days = N - total_days;
  printf("%d\n", hang_out_days);
  return 0;
}
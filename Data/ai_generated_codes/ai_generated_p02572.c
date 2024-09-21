#include <stdio.h>

#define MOD 1000000007

int main() {
  // N: the number of integers
  int N;
  scanf("%d", &N);

  // A: the array of integers
  long long A[200000];
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  // sum: the sum of A_i * A_j over all pairs (i, j) where i < j
  long long sum = 0;
  for (int i = 0; i < N - 1; i++) {
    // Calculate the sum of A[i] * A[j] for j > i
    for (int j = i + 1; j < N; j++) {
      sum = (sum + A[i] * A[j]) % MOD;
    }
  }

  printf("%lld\n", sum);
  return 0;
}
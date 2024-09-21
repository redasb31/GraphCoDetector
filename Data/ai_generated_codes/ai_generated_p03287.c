#include <stdio.h>

int main() {
  // Read input
  int N, M;
  scanf("%d %d", &N, &M);

  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the prefix sum
  long long prefixSum[N + 1];
  prefixSum[0] = 0;
  for (int i = 1; i <= N; i++) {
    prefixSum[i] = prefixSum[i - 1] + A[i - 1];
  }

  // Calculate the number of pairs
  long long count = 0;
  for (int l = 1; l <= N; l++) {
    for (int r = l; r <= N; r++) {
      // Check if the sum of candies is a multiple of M
      if ((prefixSum[r] - prefixSum[l - 1]) % M == 0) {
        count++;
      }
    }
  }

  // Print the result
  printf("%lld\n", count);

  return 0;
}
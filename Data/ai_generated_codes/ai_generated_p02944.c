#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000
#define MAX_L 200000
#define MAX_A 1000000000

int main() {
  int N, L;
  int A[MAX_N];
  long long dp[MAX_N + 1][MAX_L + 1] = {0}; // dp[i][k]: number of subsequences ending at A[i] that belong to level (k, L)
  long long result = 0;

  // Input
  scanf("%d %d", &N, &L);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Base case: for each element A[i], it belongs to level (A[i], L)
  for (int i = 0; i < N; i++) {
    dp[i + 1][A[i]]++;
  }

  // DP for each level
  for (int k = 1; k <= MAX_A; k++) {
    for (int i = 1; i <= N; i++) {
      // If current element is k, it contributes to the subsequences of level (k, L)
      if (A[i - 1] == k) {
        dp[i][k] += dp[i - 1][k]; // Add subsequences ending at previous element
      }

      // Consider subsequences of level (k - 1, L) to form level (k, L) subsequences
      for (int j = i - 1; j >= 0 && i - j < L; j--) {
        dp[i][k] += dp[j][k - 1]; // Add subsequences ending at previous positions of level (k - 1, L)
      }
    }
  }

  // Sum all subsequences belonging to any level (k, L)
  for (int k = 1; k <= MAX_A; k++) {
    for (int i = 1; i <= N; i++) {
      result += dp[i][k];
    }
  }

  // Output
  printf("%lld\n", result);

  return 0;
}
#include <stdio.h>

#define MOD 1000000007

int N;
int a[21][21];

int dp[1 << 21];

int main() {
  scanf("%d", &N);

  // Read the compatibility matrix
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  // Initialize DP table
  dp[0] = 1;

  // Iterate over all possible subsets of women
  for (int i = 1; i < (1 << N); ++i) {
    // Find the last woman included in the subset
    int lastWoman = 0;
    for (int j = 0; j < N; ++j) {
      if ((i >> j) & 1) {
        lastWoman = j;
      }
    }

    // Try pairing the last woman with each man
    for (int j = 0; j < N; ++j) {
      // Check compatibility
      if (a[j][lastWoman]) {
        // Remove the man's bit from the subset
        int subset = i ^ (1 << j);
        // Update DP table
        dp[i] = (dp[i] + dp[subset]) % MOD;
      }
    }
  }

  // The final answer is the number of ways to pair all women
  printf("%d\n", dp[(1 << N) - 1]);
  return 0;
}
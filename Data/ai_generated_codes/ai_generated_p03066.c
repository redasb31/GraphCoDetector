#include <stdio.h>

#define MOD 998244353

// dp[i][j] represents the number of sequences of length i ending with j
// that don't contain a contiguous subsequence summing to X.
long long dp[3001][3];

int main() {
  int N, X;
  scanf("%d %d", &N, &X);

  // Base case: sequences of length 1
  dp[1][0] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;

  // Iterate through sequence lengths
  for (int i = 2; i <= N; i++) {
    // Iterate through possible ending digits
    for (int j = 0; j <= 2; j++) {
      // Iterate through possible previous digits
      for (int k = 0; k <= 2; k++) {
        // Check if adding current digit to previous digit creates a sum of X
        if (j + k != X) {
          // If not, add the count of sequences ending with k to the count of
          // sequences ending with j.
          dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
      }
    }
  }

  // Sum up the counts for all possible ending digits to get the total count.
  long long total = 0;
  for (int i = 0; i <= 2; i++) {
    total = (total + dp[N][i]) % MOD;
  }

  printf("%lld\n", total);
  return 0;
}
#include <stdio.h>

#define MOD 998244353

int main() {
  int N;
  scanf("%d", &N);

  // h[i] represents the number of remaining squares in the i-th column
  int h[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d", &h[i]);
  }

  // dp[i][j] represents the number of ways to place rooks in the first i columns
  // such that the last j columns have rooks in their bottommost squares
  long long dp[N + 1][N + 1];
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      dp[i][j] = 0;
    }
  }

  // Base case: if there are no columns, there is one way to place rooks
  dp[0][0] = 1;

  // Iterate over the columns
  for (int i = 1; i <= N; ++i) {
    // Iterate over the number of columns with rooks in the bottommost square
    for (int j = 0; j <= N; ++j) {
      // If the current column has a rook in the bottommost square
      if (j > 0) {
        // We can place a rook in the current column's bottommost square
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
      }
      // If the current column has no rook in the bottommost square
      if (j < h[i - 1]) {
        // We can place a rook in the current column
        dp[i][j] = (dp[i][j] + dp[i - 1][j] * (h[i - 1] - j)) % MOD;
      }
    }
  }

  // The answer is the number of ways to place rooks in all N columns
  // with the last N columns having rooks in their bottommost squares
  printf("%lld\n", dp[N][N]);

  return 0;
}
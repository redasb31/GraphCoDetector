#include <stdio.h>

#define MOD 1000000007

long long int dp[101][1000001];

int main() {
  int N;
  scanf("%d", &N);

  int h[101];
  for (int i = 1; i <= N; i++) {
    scanf("%d", &h[i]);
  }

  // Base case: Only one column
  dp[1][0] = 1;
  dp[1][1] = 2;

  // DP: Calculate ways for each column
  for (int i = 2; i <= N; i++) {
    // Initialize the dp for the current column
    for (int j = 0; j <= h[i]; j++) {
      dp[i][j] = 0;
    }

    // Iterate through the previous column
    for (int j = 0; j <= h[i - 1]; j++) {
      // Calculate the ways for the current column based on the previous column
      for (int k = 0; k <= h[i]; k++) {
        // Check if the current row in the previous column is valid
        if (k <= j && k <= h[i - 1] && (j - k) >= 0) {
          // Calculate the ways for the current column
          dp[i][k] = (dp[i][k] + dp[i - 1][j]) % MOD;
        }
      }
    }
  }

  // Print the answer
  long long int ans = 0;
  for (int i = 0; i <= h[N]; i++) {
    ans = (ans + dp[N][i]) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
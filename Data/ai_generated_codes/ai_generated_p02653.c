#include <stdio.h>

#define MOD 1000000007

int main() {
  int N, A, B;
  scanf("%d %d %d", &N, &A, &B);

  // dp[i][j] represents the number of ways to make the first i characters
  // of the string with j being the last character.
  long long dp[N + 1][2] = {0};

  // Base case: The first character can be either 0 or 1.
  dp[1][0] = 1;
  dp[1][1] = 1;

  // Iterate through the string, building up the dp table.
  for (int i = 2; i <= N; i++) {
    // If we can place A consecutive 0s, add the number of ways to make the
    // string up to the (i-A)th character with the last character being 0.
    if (i >= A) {
      dp[i][0] = (dp[i][0] + dp[i - A][0]) % MOD;
    }
    // If we can place A consecutive 1s, add the number of ways to make the
    // string up to the (i-A)th character with the last character being 1.
    if (i >= B) {
      dp[i][1] = (dp[i][1] + dp[i - B][1]) % MOD;
    }
    // If we can place B consecutive 0s, add the number of ways to make the
    // string up to the (i-B)th character with the last character being 0.
    if (i >= B) {
      dp[i][0] = (dp[i][0] + dp[i - B][1]) % MOD;
    }
    // If we can place B consecutive 1s, add the number of ways to make the
    // string up to the (i-B)th character with the last character being 1.
    if (i >= A) {
      dp[i][1] = (dp[i][1] + dp[i - A][0]) % MOD;
    }
  }

  // The total number of ways is the sum of the number of ways to make the
  // string ending with 0 or 1.
  printf("%lld\n", (dp[N][0] + dp[N][1]) % MOD);

  return 0;
}
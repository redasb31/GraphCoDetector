#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long dp[71][71][2];

int main() {
  int n, k;
  char s[71];

  scanf("%d %d\n", &n, &k);
  scanf("%s", s);

  // Base case: no operations performed
  for (int i = 0; i <= n; i++) {
    dp[0][i][0] = 1; // All white
    dp[0][i][1] = 1; // All white
  }

  // Iterate over each operation
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      // If current operation is 'r', we can paint any segment red
      if (s[i - 1] == 'r') {
        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0]) % MOD; // Keep white
        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][1]) % MOD; // Paint red
        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % MOD; // Keep red
      }

      // If current operation is 'b', we can only paint a segment blue if it's all red
      if (s[i - 1] == 'b') {
        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % MOD; // Keep blue
      }
    }
  }

  // Total number of color sequences
  long long result = (dp[k][n][0] + dp[k][n][1]) % MOD;

  printf("%lld\n", result);
  return 0;
}
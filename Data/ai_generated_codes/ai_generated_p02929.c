#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long dp[100005][2]; // dp[i][j] stores the number of ways to make the first i squares white, with the i-th square being black (j = 0) or white (j = 1)

int main() {
  int n;
  char s[100005];

  scanf("%d\n", &n);
  scanf("%s", s);

  // Base case: For the first square, there is only one way to make it white
  dp[1][1] = 1;

  for (int i = 2; i <= 2 * n; i++) {
    // If the current square is black (s[i - 1] == 'B')
    if (s[i - 1] == 'B') {
      // If the previous square is white (s[i - 2] == 'W')
      if (s[i - 2] == 'W') {
        // We can either choose the current square with the previous one, or not
        dp[i][1] = (dp[i - 1][1] + dp[i - 2][0]) % MOD;
      } else {
        // If the previous square is black, we must choose the current square with the previous one
        dp[i][1] = dp[i - 2][0] % MOD;
      }
    } else {
      // If the current square is white (s[i - 1] == 'W')
      // If the previous square is black (s[i - 2] == 'B')
      if (s[i - 2] == 'B') {
        // We can either choose the current square with the previous one, or not
        dp[i][0] = (dp[i - 1][0] + dp[i - 2][1]) % MOD;
      } else {
        // If the previous square is white, we must choose the current square with the previous one
        dp[i][0] = dp[i - 2][1] % MOD;
      }
    }
  }

  printf("%lld\n", (dp[2 * n][0] + dp[2 * n][1]) % MOD); // Print the number of ways to make all squares white
  return 0;
}
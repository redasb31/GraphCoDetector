#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the number of ways to paint the string
long long countWays(char *s, int n) {
  // Create a 2D array to store the number of ways to paint the string up to a certain index
  long long dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));

  // Base case: If the string is empty, there is only one way to paint it
  dp[0][0] = 1;

  // Iterate over all possible substrings of the string
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      // If the characters at the current indices are the same, we can paint them either red or blue
      if (s[i - 1] == s[n - j]) {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      } else {
        // If the characters are different, we can only paint them one color
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }

  // The answer is the number of ways to paint the entire string
  return dp[n][n];
}

int main() {
  int n;
  char s[100];

  // Read input
  scanf("%d\n", &n);
  scanf("%s", s);

  // Calculate the number of ways to paint the string
  long long result = countWays(s, n);

  // Print the result
  printf("%lld\n", result);

  return 0;
}
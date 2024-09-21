#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of ways to eat cookies
long long countWays(int n, int d, int x) {
  // Create a 2D array to store the number of ways
  long long dp[d + 1][n + 1];

  // Initialize the base cases
  for (int i = 0; i <= d; i++) {
    dp[i][0] = 1; // There is one way to eat zero cookies
  }

  // Iterate over the days
  for (int i = 1; i <= d; i++) {
    // Iterate over the number of cookies
    for (int j = 1; j <= n; j++) {
      // If the number of cookies is less than the maximum allowed per day
      if (j < x) {
        // The number of ways is the same as the previous day
        dp[i][j] = dp[i - 1][j];
      } else {
        // The number of ways is the sum of the ways for the previous day
        // and the ways for the previous day with the maximum allowed cookies eaten
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - x]) % MOD;
      }
    }
  }

  // Return the number of ways to eat all the cookies
  return dp[d][n];
}

int main() {
  int n, d, x;

  // Read the input until end of input is encountered
  while (scanf("%d %d %d", &n, &d, &x) != EOF) {
    // If the input is zero, then break the loop
    if (n == 0 && d == 0 && x == 0) {
      break;
    }

    // Calculate and print the number of ways
    printf("%lld\n", countWays(n, d, x));
  }

  return 0;
}
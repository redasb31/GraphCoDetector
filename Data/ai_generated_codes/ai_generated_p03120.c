#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of strings of length n
// that are divisible by 9, with the given constraints
long long count_strings(int n, int q, int l[], int r[]) {
  // dp[i][j] represents the number of strings of length i that satisfy
  // the constraints up to the j-th interval (i.e., the first j intervals)
  long long dp[n + 1][q + 1];

  // Initialize the base cases
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= q; j++) {
      dp[i][j] = 0;
    }
  }

  // There's only 1 string of length 0
  dp[0][0] = 1;

  // Iterate over all possible lengths of the string
  for (int i = 1; i <= n; i++) {
    // Iterate over all intervals
    for (int j = 0; j <= q; j++) {
      // If the current length is within the current interval
      if (i >= l[j] && i <= r[j]) {
        // Calculate the number of strings ending in digits 0-8
        for (int k = 0; k <= 8; k++) {
          // If the string formed by digits from l[j] to i is divisible by 9
          if (((i - l[j] + 1) * k) % 9 == 0) {
            // Add the number of strings of length i-1 that satisfy the
            // previous intervals to the current dp value
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
          }
        }
      } else {
        // If the current length is not within the current interval,
        // the number of strings is the same as the previous interval
        dp[i][j] = dp[i][j - 1];
      }
    }
  }

  // Return the number of strings that satisfy all the intervals
  return dp[n][q];
}

int main() {
  int n, q, l[15], r[15];

  // Read input
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &l[i], &r[i]);
  }

  // Calculate and print the result
  printf("%lld\n", count_strings(n, q, l, r));

  return 0;
}
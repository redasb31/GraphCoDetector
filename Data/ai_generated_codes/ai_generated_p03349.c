// This code solves the given problem statement using dynamic programming.
// It calculates the number of valid sequences by considering the current sequence and its previous sequence.

#include <stdio.h>

#define MOD 1000000007

int dp[301][301]; // dp[i][j] stores the number of valid sequences of length i ending with j

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);

  // Initialize the base case for the sequence of length 0
  dp[0][0] = 1;

  // Iterate through each possible sequence length
  for (int i = 1; i <= n; i++) {
    // Iterate through each possible ending element
    for (int j = 1; j <= k; j++) {
      // Iterate through each possible previous element
      for (int prev = 1; prev <= k; prev++) {
        // If the current element is lexicographically greater than the previous element
        if (j > prev) {
          // Add the number of valid sequences with the previous element to the current element's count
          dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
        }
      }
    }
  }

  // Sum up the number of valid sequences for all possible ending elements
  int total = 0;
  for (int j = 1; j <= k; j++) {
    total = (total + dp[n][j]) % MOD;
  }

  printf("%d\n", total);

  return 0;
}
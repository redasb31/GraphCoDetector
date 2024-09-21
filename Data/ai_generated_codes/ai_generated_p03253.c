#include <stdio.h>
#define MOD 1000000007

// Function to calculate the number of factors of a number
int countFactors(int n) {
  int count = 0;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      count += 2; // Count both i and n/i
      // If i*i = n, we've counted it twice, so subtract one
      if (i * i == n) {
        count--;
      }
    }
  }
  return count;
}

// Function to calculate the number of sequences
long long countSequences(int n, int m) {
  // If n = 1, there's only one sequence possible
  if (n == 1) {
    return 1;
  }

  // Calculate the number of factors of M
  int factors = countFactors(m);

  // If the number of factors is less than n, there are no sequences
  if (factors < n) {
    return 0;
  }

  // Calculate the number of sequences using dynamic programming
  long long dp[n + 1];
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 0;
    // Iterate through all factors of M
    for (int j = 1; j * j <= m; ++j) {
      if (m % j == 0) {
        // If j is a factor of M, add dp[i - 1] to dp[i]
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
        // If j != m/j, add dp[i - 1] to dp[i] again
        if (j != m / j) {
          dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }
      }
    }
  }

  // Return the number of sequences for n integers
  return dp[n];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Calculate the number of sequences and print it
  long long result = countSequences(n, m);
  printf("%lld\n", result);

  return 0;
}
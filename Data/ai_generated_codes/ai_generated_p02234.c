#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications
int matrixChainMultiplication(int p[], int n) {
  // Create a table to store the minimum number of scalar multiplications
  int dp[n][n];

  // Initialize the table
  for (int i = 1; i < n; i++) {
    dp[i][i] = 0;
  }

  // Iterate over the sub-problems
  for (int len = 2; len < n; len++) {
    for (int i = 1; i <= n - len; i++) {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;

      // Find the minimum cost of multiplying the sub-chain from i to j
      for (int k = i; k < j; k++) {
        int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (cost < dp[i][j]) {
          dp[i][j] = cost;
        }
      }
    }
  }

  // Return the minimum number of scalar multiplications
  return dp[1][n - 1];
}

int main() {
  int n;
  scanf("%d", &n);

  // Store the dimensions of the matrices
  int p[n + 1];
  for (int i = 0; i <= n; i++) {
    if (i == 0 || i == n) {
      // Dummy values for the first and last dimensions
      p[i] = 1;
    } else {
      int r, c;
      scanf("%d %d", &r, &c);
      p[i] = c;
    }
  }

  // Find the minimum number of scalar multiplications
  int minMultiplications = matrixChainMultiplication(p, n);

  // Print the result
  printf("%d\n", minMultiplications);

  return 0;
}
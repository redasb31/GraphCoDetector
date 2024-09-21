#include <stdio.h>

// Function to find the minimum cost to combine all slimes
int minCost(int a[], int n) {
  // Create a DP table to store the minimum cost to combine slimes from i to j
  int dp[n][n];
  // Initialize DP table
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }
  // Iterate through all possible subarrays
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      // Calculate the minimum cost to combine slimes from i to j
      dp[i][j] = dp[i + 1][j] + a[i] + a[i + 1];
      // Find the minimum cost by considering all possible combinations
      for (int k = i + 1; k < j; k++) {
        dp[i][j] = (dp[i][j] < dp[i][k] + dp[k][j]) ? dp[i][j] : dp[i][k] + dp[k][j];
      }
    }
  }
  // Return the minimum cost to combine all slimes
  return dp[0][n - 1];
}

int main() {
  int n;
  // Read the number of slimes
  scanf("%d", &n);
  // Create an array to store the size of each slime
  int a[n];
  // Read the size of each slime
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  // Print the minimum cost to combine all slimes
  printf("%d\n", minCost(a, n));
  return 0;
}
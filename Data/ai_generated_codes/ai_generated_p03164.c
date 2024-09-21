#include <stdio.h>

// Function to find the maximum value that can be obtained with a knapsack of capacity W
int knapsack(int N, int W, int w[], int v[]) {
  // Create a 2D array to store the maximum value for each capacity from 0 to W
  int dp[N + 1][W + 1];

  // Initialize the first row and column to 0
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= W; j++) {
    dp[0][j] = 0;
  }

  // Iterate over each item and capacity
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      // If the weight of the current item is greater than the current capacity,
      // the maximum value is the same as the previous row
      if (w[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      }
      // Otherwise, the maximum value is the greater of:
      // - The maximum value without the current item
      // - The value of the current item plus the maximum value for the remaining capacity
      else {
        dp[i][j] =
            (v[i - 1] + dp[i - 1][j - w[i - 1]]) > dp[i - 1][j]
                ? (v[i - 1] + dp[i - 1][j - w[i - 1]])
                : dp[i - 1][j];
      }
    }
  }

  // Return the maximum value for the given capacity
  return dp[N][W];
}

int main() {
  int N, W;
  scanf("%d %d", &N, &W);

  // Create arrays to store the weights and values of the items
  int w[N], v[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &w[i], &v[i]);
  }

  // Calculate and print the maximum value
  printf("%d\n", knapsack(N, W, w, v));
  return 0;
}
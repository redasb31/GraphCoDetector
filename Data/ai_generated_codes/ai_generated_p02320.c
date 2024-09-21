#include <stdio.h>

// Function to find the maximum total value of items in the knapsack
int knapsack(int N, int W, int v[], int w[], int m[]) {
  // dp[i][j] represents the maximum value achievable using items from 0 to i-1 with a weight limit of j
  int dp[N + 1][W + 1];

  // Initialize the dp table
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i][j] = 0;
    }
  }

  // Iterate over each item
  for (int i = 1; i <= N; i++) {
    // Iterate over each possible weight limit
    for (int j = 1; j <= W; j++) {
      // If the current item's weight is less than or equal to the weight limit
      if (w[i - 1] <= j) {
        // Calculate the maximum value achievable by including the current item
        int max_value = 0;
        for (int k = 0; k <= m[i - 1] && k * w[i - 1] <= j; k++) {
          max_value =
              max(max_value,
                  dp[i - 1][j - k * w[i - 1]] + k * v[i - 1]);
        }
        // Update the dp table with the maximum value
        dp[i][j] = max(dp[i - 1][j], max_value);
      } else {
        // If the current item's weight is greater than the weight limit, then the value is the same as the previous row
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Return the maximum value achievable with the given weight limit
  return dp[N][W];
}

int main() {
  // Input the number of items and the weight limit
  int N, W;
  scanf("%d %d", &N, &W);

  // Input the value, weight, and limitation of each item
  int v[N], w[N], m[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &v[i], &w[i], &m[i]);
  }

  // Call the knapsack function to find the maximum value
  int max_value = knapsack(N, W, v, w, m);

  // Output the maximum value
  printf("%d\n", max_value);

  return 0;
}
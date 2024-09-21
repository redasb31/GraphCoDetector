#include <stdio.h>

// Function to find the maximum total value of items in the knapsack
int knapsack(int N, int W, int v[], int w[], int m[]) {
  // Create a 2D array to store the maximum value for each weight limit and number of items
  int dp[N + 1][W + 1];
  // Initialize the array with 0s
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i][j] = 0;
    }
  }
  // Iterate over the items
  for (int i = 1; i <= N; i++) {
    // Iterate over the weight limits
    for (int j = 1; j <= W; j++) {
      // If the current weight is less than or equal to the current weight limit
      if (w[i - 1] <= j) {
        // Calculate the maximum value by taking the maximum between:
        // - The value without taking the current item
        // - The value with taking the current item (including the value of the previous items with the same item number)
        dp[i][j] =
            max(dp[i - 1][j],
                dp[i - 1][j - w[i - 1]] + v[i - 1] * min(j / w[i - 1], m[i - 1]));
      } else {
        // If the weight of the current item is greater than the weight limit,
        // the value is the same as the previous item
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  // Return the maximum value for the given weight limit
  return dp[N][W];
}

// Function to find the maximum of two integers
int max(int a, int b) {
  return a > b ? a : b;
}

// Function to find the minimum of two integers
int min(int a, int b) {
  return a < b ? a : b;
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

  // Find the maximum total value of items in the knapsack
  int max_value = knapsack(N, W, v, w, m);

  // Output the maximum total value
  printf("%d\n", max_value);

  return 0;
}
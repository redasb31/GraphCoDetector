#include <stdio.h>

// Function to solve the 0-1 knapsack problem using dynamic programming
int knapsack(int N, int W, int values[], int weights[]) {
  // Create a 2D array to store the maximum values for each weight capacity
  int dp[N + 1][W + 1];

  // Initialize the first row and column of the dp array to 0
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= W; j++) {
    dp[0][j] = 0;
  }

  // Iterate through the items and weight capacities
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      // If the weight of the current item is less than or equal to the current weight capacity
      if (weights[i - 1] <= j) {
        // Choose the maximum value between including the current item and excluding it
        dp[i][j] =
            // Include the current item if its weight is less than or equal to the current weight capacity
            // and add its value to the maximum value of the knapsack with the remaining weight capacity
            // excluding the current item.
            (values[i - 1] + dp[i - 1][j - weights[i - 1]]) >
            // Exclude the current item and take the maximum value of the knapsack with the current weight capacity
            // excluding the current item.
            dp[i - 1][j]
                ? values[i - 1] + dp[i - 1][j - weights[i - 1]]
                : dp[i - 1][j];
      } else {
        // If the weight of the current item is greater than the current weight capacity
        // then exclude the current item and take the maximum value of the knapsack with the current weight capacity
        // excluding the current item.
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Return the maximum value of the knapsack with the given weight capacity
  return dp[N][W];
}

int main() {
  int N, W; // Number of items and knapsack capacity
  scanf("%d %d", &N, &W);

  // Declare arrays to store the values and weights of the items
  int values[N];
  int weights[N];

  // Read the values and weights of the items
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &values[i], &weights[i]);
  }

  // Solve the knapsack problem and print the maximum value
  printf("%d\n", knapsack(N, W, values, weights));

  return 0;
}
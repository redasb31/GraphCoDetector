#include <stdio.h>

// Function to find the maximum value of items that can be put in a knapsack of capacity W
long long knapsack(long long N, long long W, long long values[], long long weights[]) {
  // Create a 2D array to store the maximum value for each capacity (0 to W) and each item (0 to N)
  long long dp[N + 1][W + 1]; 
  // Initialize all values in the array to 0
  for (long long i = 0; i <= N; i++) {
    for (long long j = 0; j <= W; j++) {
      dp[i][j] = 0;
    }
  }

  // Iterate through each item
  for (long long i = 1; i <= N; i++) {
    // Iterate through each capacity
    for (long long j = 1; j <= W; j++) {
      // If the current item's weight is less than or equal to the current capacity
      if (weights[i - 1] <= j) {
        // Calculate the maximum value by considering two options:
        // 1. Include the current item in the knapsack
        // 2. Exclude the current item from the knapsack
        dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
      } else {
        // If the current item's weight is greater than the current capacity, exclude the item
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // The maximum value is stored in the last cell of the dp array
  return dp[N][W];
}

// Function to find the maximum of two numbers
long long max(long long a, long long b) {
  return (a > b) ? a : b;
}

int main() {
  long long N, W;
  // Read the number of items and the knapsack capacity
  scanf("%lld %lld", &N, &W);

  // Declare arrays to store the values and weights of the items
  long long values[N];
  long long weights[N];

  // Read the values and weights of the items
  for (long long i = 0; i < N; i++) {
    scanf("%lld %lld", &values[i], &weights[i]);
  }

  // Call the knapsack function to find the maximum value
  long long result = knapsack(N, W, values, weights);

  // Print the maximum value
  printf("%lld\n", result);

  return 0;
}
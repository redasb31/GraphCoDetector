#include <stdio.h>

// Function to find the maximum value of items in the knapsack
int knapsack(int N, int W, int v[], int w[]) {
  // Create a 2D array to store the maximum value for each capacity and item
  int dp[N + 1][W + 1]; 

  // Initialize the array with 0
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i][j] = 0;
    }
  }

  // Iterate through each item
  for (int i = 1; i <= N; i++) {
    // Iterate through each capacity
    for (int j = 1; j <= W; j++) {
      // If the weight of the current item is less than or equal to the current capacity
      if (w[i - 1] <= j) {
        // Calculate the maximum value between including the current item and excluding it
        dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
      } else {
        // If the weight of the current item is greater than the current capacity, exclude the current item
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Return the maximum value at the last row and last column of the dp array
  return dp[N][W];
}

// Function to find the maximum of two integers
int max(int a, int b) {
  return (a > b) ? a : b;
}

int main() {
  int N, W;

  // Input the number of items and the knapsack capacity
  scanf("%d %d", &N, &W);

  // Input the value and weight of each item
  int v[N], w[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &v[i], &w[i]);
  }

  // Calculate the maximum value of items in the knapsack
  int result = knapsack(N, W, v, w);

  // Output the maximum value
  printf("%d\n", result);

  return 0;
}
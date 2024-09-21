#include <stdio.h>

#define MAX_N 100
#define MAX_W 100000

int N, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

// Function to find the maximum value that can be obtained
int knapsack(int n, int weight) {
  // Base case: If we have no items or no weight capacity, the value is 0
  if (n == 0 || weight == 0) {
    return 0;
  }
  // If we have already calculated the value for this n and weight, return it
  if (dp[n][weight] != -1) {
    return dp[n][weight];
  }
  // If the weight of the current item is greater than the remaining weight capacity
  if (w[n - 1] > weight) {
    // We can't include the current item, so the maximum value is the same as without it
    dp[n][weight] = knapsack(n - 1, weight);
  } else {
    // We have two choices: include or exclude the current item
    // Include the current item:
    int include = v[n - 1] + knapsack(n - 1, weight - w[n - 1]);
    // Exclude the current item:
    int exclude = knapsack(n - 1, weight);
    // Choose the option that gives the maximum value
    dp[n][weight] = (include > exclude) ? include : exclude;
  }
  // Return the calculated value
  return dp[n][weight];
}

int main() {
  // Read input
  scanf("%d %d", &N, &W);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &w[i], &v[i]);
  }
  // Initialize the dp array with -1 to indicate uncalculated values
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[i][j] = -1;
    }
  }
  // Calculate and print the maximum value
  printf("%d\n", knapsack(N, W));
  return 0;
}
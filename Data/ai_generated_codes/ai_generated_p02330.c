#include <stdio.h>

// Function to calculate the number of combinations
int count_combinations(int n, int k, int l, int r, int *arr) {
  // Create a 2D array to store the number of combinations for each sum
  int dp[k + 1][r + 1];

  // Initialize the dp array with 0
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= r; j++) {
      dp[i][j] = 0;
    }
  }

  // Base case: 0 coins, no sum possible
  for (int j = 0; j <= r; j++) {
    dp[0][j] = 0;
  }

  // Iterate over the coins
  for (int i = 1; i <= k; i++) {
    // Iterate over the possible sums
    for (int j = 0; j <= r; j++) {
      // If the current sum is less than the current coin value, 
      // the combination is the same as the previous combination
      if (j < arr[i - 1]) {
        dp[i][j] = dp[i - 1][j];
      } else {
        // Otherwise, the combination is the sum of the previous combination
        // and the combination without the current coin
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
      }
    }
  }

  // Calculate the number of combinations for the range [l, r]
  int count = 0;
  for (int i = l; i <= r; i++) {
    count += dp[k][i];
  }

  // Return the number of combinations
  return count;
}

int main() {
  // Read the input values
  int n, k, l, r;
  scanf("%d %d %d %d", &n, &k, &l, &r);

  // Create an array to store the coin values
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Calculate the number of combinations
  int count = count_combinations(n, k, l, r, arr);

  // Print the number of combinations
  printf("%d\n", count);

  return 0;
}
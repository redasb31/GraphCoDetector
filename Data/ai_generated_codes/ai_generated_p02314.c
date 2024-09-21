#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins required to make change
int minCoins(int n, int m, int coins[]) {
  // Create a table to store the minimum number of coins required for each amount
  int dp[n + 1]; 
  dp[0] = 0; // Base case: 0 coins needed for 0 amount

  // Initialize the table with a large value (INT_MAX) to indicate an impossible solution
  for (int i = 1; i <= n; i++) {
    dp[i] = INT_MAX;
  }

  // Iterate through all amounts from 1 to n
  for (int i = 1; i <= n; i++) {
    // Iterate through all coins
    for (int j = 0; j < m; j++) {
      // If the current coin's value is less than or equal to the current amount
      if (coins[j] <= i) {
        // If the current amount minus the coin's value has a solution in the table
        if (dp[i - coins[j]] != INT_MAX) {
          // Calculate the number of coins required for the current amount
          int currentCoins = dp[i - coins[j]] + 1;

          // Update the table if the current solution is better than the previous best
          if (currentCoins < dp[i]) {
            dp[i] = currentCoins;
          }
        }
      }
    }
  }

  // Return the minimum number of coins required for the total amount
  return dp[n];
}

int main() {
  int n, m; // Total amount and number of coins
  scanf("%d %d", &n, &m);

  int coins[m]; // Array to store the coin denominations
  for (int i = 0; i < m; i++) {
    scanf("%d", &coins[i]);
  }

  // Call the minCoins function to find the minimum number of coins
  int minCoinsNeeded = minCoins(n, m, coins);

  // Print the result
  printf("%d\n", minCoinsNeeded);

  return 0;
}
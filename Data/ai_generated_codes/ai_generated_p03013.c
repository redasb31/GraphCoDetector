#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of ways to climb the stairs
long long climbStairs(int n, int m, int *brokenSteps) {
  // Create a DP array to store the number of ways to reach each step
  long long dp[n + 1];

  // Initialize the base cases
  dp[0] = 1;
  dp[1] = 1;

  // Iterate through the steps
  for (int i = 2; i <= n; i++) {
    // If the current step is not broken
    if (i != brokenSteps[0] && (m == 0 || i != brokenSteps[1]) && (m > 1 || i != brokenSteps[2]) && (m > 2 || i != brokenSteps[3]) && (m > 3 || i != brokenSteps[4])) {
      // The number of ways to reach the current step is the sum of the number of ways to reach the previous two steps
      dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    } else {
      // If the current step is broken, there are no ways to reach it
      dp[i] = 0;
    }
  }

  // Return the number of ways to reach the top step
  return dp[n];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Read the broken steps
  int brokenSteps[5];
  for (int i = 0; i < m; i++) {
    scanf("%d", &brokenSteps[i]);
  }

  // Calculate the number of ways to climb the stairs
  long long ways = climbStairs(n, m, brokenSteps);

  // Print the result
  printf("%lld\n", ways);

  return 0;
}
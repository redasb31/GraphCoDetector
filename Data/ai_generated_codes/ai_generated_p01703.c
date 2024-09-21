#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum expected time to complete the game
double minExpectedTime(int n, double *p) {
  // Create an array to store the minimum expected time to reach each checkpoint
  double *dp = (double *)malloc((n + 1) * sizeof(double));

  // Initialize the minimum expected time to reach the first checkpoint
  dp[0] = 0;

  // Iterate through the checkpoints
  for (int i = 1; i <= n; i++) {
    // Calculate the expected time to reach the current checkpoint without saving
    double noSave = dp[i - 1] + 1;

    // Calculate the expected time to reach the current checkpoint with saving
    double save = dp[i - 1] + 1 + (1 - p[i - 1]) * (1 + dp[i - 1]);

    // Choose the minimum of the two options
    dp[i] = (noSave < save) ? noSave : save;
  }

  // Return the minimum expected time to reach the final checkpoint
  double minTime = dp[n];

  // Free the memory allocated for the dp array
  free(dp);

  // Return the minimum expected time
  return minTime;
}

int main() {
  // Read the input
  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    // Allocate memory for the winning probabilities
    double *p = (double *)malloc(n * sizeof(double));

    // Read the winning probabilities
    for (int i = 0; i < n; i++) {
      scanf("%lf", &p[i]);
    }

    // Calculate and print the minimum expected time
    printf("%.10lf\n", minExpectedTime(n, p));

    // Free the memory allocated for the winning probabilities
    free(p);
  }

  return 0;
}
#include <stdio.h>
#include <math.h>

#define MAX_N 100
#define MAX_M 100

double vectors[MAX_M][MAX_N];
double dp[MAX_M];

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  // Read the vectors
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%lf", &vectors[i][j]);
    }
  }

  // Initialize DP table
  dp[0] = 0;
  for (int i = 1; i < M; ++i) {
    dp[i] = 1e18; // Set to a large value initially
  }

  // Calculate minimum squared length
  for (int i = 1; i < M; ++i) {
    // Calculate squared length of the vector itself
    double squared_length = 0;
    for (int j = 0; j < N; ++j) {
      squared_length += vectors[i][j] * vectors[i][j];
    }

    // Update DP table
    dp[i] = squared_length;

    // Iterate through previous vectors
    for (int j = 0; j < i; ++j) {
      // Calculate squared length of the difference vector
      double diff_squared_length = 0;
      for (int k = 0; k < N; ++k) {
        diff_squared_length += (vectors[i][k] - vectors[j][k]) * (vectors[i][k] - vectors[j][k]);
      }

      // Update DP table if the difference vector is smaller
      dp[i] = fmin(dp[i], dp[j] + diff_squared_length);
    }
  }

  // Print the minimum squared length
  printf("%.6lf\n", dp[M - 1]);

  return 0;
}
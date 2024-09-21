#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

int N;
int A[MAX_N * 2][MAX_N * 2];
int dp[1 << (MAX_N * 2)];

// Function to calculate the number of ways to divide the points
int count_ways(int mask) {
  // Base case: All points are paired
  if (mask == (1 << (2 * N)) - 1) {
    return 1;
  }

  // If this state has already been calculated
  if (dp[mask] != -1) {
    return dp[mask];
  }

  int count = 0;
  for (int i = 0; i < 2 * N; i++) {
    // If the point is not already paired
    if (!(mask & (1 << i))) {
      for (int j = i + 1; j < 2 * N; j++) {
        // If the points are connected and not already paired
        if (A[i][j] && !(mask & (1 << j))) {
          // Recursively calculate the number of ways for the remaining points
          count += count_ways(mask | (1 << i) | (1 << j));
        }
      }
    }
  }

  // Store the result for future reference
  dp[mask] = count;
  return count;
}

int main() {
  scanf("%d", &N);

  // Read the adjacency matrix
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < 2 * N; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Initialize dp array
  for (int i = 0; i < (1 << (2 * N)); i++) {
    dp[i] = -1;
  }

  // Calculate and print the number of ways
  printf("%d\n", count_ways(0));

  return 0;
}
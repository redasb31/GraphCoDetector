#include <stdio.h>
#include <limits.h>

#define MAX_N 100

int N;
int C[MAX_N][MAX_N]; // Cost matrix

int dp[MAX_N][1 << MAX_N]; // dp[i][mask] : minimum cost to visit areas represented by mask, ending at area i

// Function to calculate the minimum cost to visit all areas
int calculate_min_cost(int start) {
  // Initialize dp table
  for (int i = 0; i < N; i++) {
    for (int mask = 0; mask < (1 << N); mask++) {
      dp[i][mask] = INT_MAX;
    }
  }

  // Base case: Visiting only the starting area
  dp[start][1 << start] = 0;

  // Iterate over all possible masks (subsets of areas)
  for (int mask = 1; mask < (1 << N); mask++) {
    // Iterate over all areas
    for (int i = 0; i < N; i++) {
      // If area i is included in the mask
      if (mask & (1 << i)) {
        // Iterate over all previous areas that could lead to area i
        for (int j = 0; j < N; j++) {
          // If area j is included in the mask and it's not the same as area i
          if (mask & (1 << j) && j != i) {
            // Update the minimum cost to reach area i with the current mask
            dp[i][mask] = (dp[i][mask] < dp[j][mask ^ (1 << i)] + C[j][i]) ? dp[i][mask] : dp[j][mask ^ (1 << i)] + C[j][i];
          }
        }
      }
    }
  }

  // Minimum cost to visit all areas
  int min_cost = INT_MAX;
  for (int i = 0; i < N; i++) {
    min_cost = (min_cost < dp[i][(1 << N) - 1]) ? min_cost : dp[i][(1 << N) - 1];
  }

  return min_cost;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &C[i][j]);
    }
  }

  // Calculate the minimum cost starting from each area
  int min_cost = INT_MAX;
  for (int i = 0; i < N; i++) {
    min_cost = (min_cost < calculate_min_cost(i)) ? min_cost : calculate_min_cost(i);
  }

  printf("%d\n", min_cost);
  return 0;
}
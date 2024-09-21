#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_W 100000

int N, C;
int b[MAX_N + 1];
int w[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];

// Function to calculate the labor cost for operation A
int cost_A(int l, int r) {
  int sum = 0;
  for (int i = l + 1; i <= r; i++) {
    sum += w[b[i]];
  }
  return sum + C * (r - l) * w[b[l]];
}

// Function to calculate the labor cost for operation B
int cost_B(int l, int r) {
  int sum = 0;
  for (int i = l; i <= r - 1; i++) {
    sum += w[b[i]];
  }
  return sum + C * (r - l) * w[b[r]];
}

// Function to calculate the minimum labor cost to restore the original order
int min_labor() {
  // Initialize the dp array
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      dp[i][j] = 1000000000; // Set to a large value initially
    }
  }

  // Base case: no books to restore
  dp[0][0] = 0;

  // Iterate over the permutation, building up the dp array
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      // If the current book is already in its correct position, do nothing
      if (b[i] == i) {
        dp[i][j] = dp[i - 1][j];
      } else {
        // Try operation A: remove the current book and insert it to the right
        if (j >= 1) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost_A(j - 1, i));
        }
        // Try operation B: remove the current book and insert it to the left
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost_B(j, i));
      }
    }
  }

  // The minimum labor cost is in dp[N][N]
  return dp[N][N];
}

int main() {
  // Read input
  scanf("%d %d", &N, &C);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &b[i], &w[b[i]]);
  }

  // Calculate the minimum labor cost
  int min_labor_cost = min_labor();

  // Print the result
  printf("%d\n", min_labor_cost);

  return 0;
}
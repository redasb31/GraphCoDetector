#include <stdio.h>
#include <limits.h>

#define MAX_N 18
#define MAX_VALUE 50

int dp[MAX_N + 1][MAX_VALUE + 1][MAX_VALUE + 1]; // dp[i][j][k] stores the minimum operations required to make the sequence non-decreasing from card i to card N, where j is the value of card i facing up, and k is the value of card (i-1) facing up.

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  int N, A[MAX_N], B[MAX_N];
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }

  // Initialize the dp table with INT_MAX
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= MAX_VALUE; j++) {
      for (int k = 0; k <= MAX_VALUE; k++) {
        dp[i][j][k] = INT_MAX;
      }
    }
  }

  // Base case: when we have only one card left
  for (int j = 0; j <= MAX_VALUE; j++) {
    dp[N][j][j] = 0;
  }

  // Iterate backwards through the cards
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= MAX_VALUE; j++) {
      for (int k = 0; k <= MAX_VALUE; k++) {
        // Case 1: Card i is facing up with value j, and card (i+1) is facing up with value k
        // We can either flip both cards or leave them as they are
        if (j >= k) {
          dp[i][j][k] = min(dp[i][j][k], dp[i + 1][k][j]); // Flip both cards
          dp[i][j][k] = min(dp[i][j][k], dp[i + 1][k][j] + 1); // Leave as they are
        }
        // Case 2: Card i is facing up with value j, and card (i+1) is facing down with value k
        // We must flip card (i+1)
        if (j >= B[i + 1]) {
          dp[i][j][k] = min(dp[i][j][k], dp[i + 1][B[i + 1]][j] + 1); 
        }
        // Case 3: Card i is facing down with value j, and card (i+1) is facing up with value k
        // We must flip card i
        if (A[i] >= k) {
          dp[i][j][k] = min(dp[i][j][k], dp[i + 1][k][A[i]] + 1);
        }
        // Case 4: Card i is facing down with value j, and card (i+1) is facing down with value k
        // We must flip both cards
        if (A[i] >= B[i + 1]) {
          dp[i][j][k] = min(dp[i][j][k], dp[i + 1][B[i + 1]][A[i]] + 1);
        }
      }
    }
  }

  int min_operations = dp[0][A[0]][A[0]];
  if (min_operations == INT_MAX) {
    printf("-1\n");
  } else {
    printf("%d\n", min_operations);
  }

  return 0;
}
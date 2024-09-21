#include <stdio.h>

#define MAX_N 50
#define MAX_K 50

int N, K;
int A[MAX_N][MAX_N];
int dp[MAX_N + 1][MAX_K + 1][MAX_N + 1];
char chosen[MAX_N][MAX_N];

int main() {
  // Input
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &A[i][j]);
    }
  }

  // DP Initialization
  for (int i = 0; i <= N; ++i) {
    for (int k = 0; k <= K; ++k) {
      for (int j = 0; j <= N; ++j) {
        dp[i][k][j] = 0;
      }
    }
  }

  // DP Calculation
  for (int i = 1; i <= N; ++i) {
    for (int k = 1; k <= K; ++k) {
      for (int j = 1; j <= N; ++j) {
        // Choose the current square
        dp[i][k][j] = dp[i - 1][k - 1][j - 1] + A[i - 1][j - 1];
        // Don't choose the current square
        dp[i][k][j] =
            (dp[i][k][j] > dp[i - 1][k][j - 1]) ? dp[i][k][j]
                                               : dp[i - 1][k][j - 1];
        // Don't choose the current square (using previous row's state)
        dp[i][k][j] =
            (dp[i][k][j] > dp[i - 1][k][j]) ? dp[i][k][j] : dp[i - 1][k][j];
      }
    }
  }

  // Backtracking to find the chosen squares
  int i = N, k = K, j = N;
  while (i > 0 && k > 0 && j > 0) {
    // If choosing the current square leads to the maximum value, mark it
    if (dp[i][k][j] == dp[i - 1][k - 1][j - 1] + A[i - 1][j - 1]) {
      chosen[i - 1][j - 1] = 'X';
      i--;
      k--;
      j--;
    } else {
      // Otherwise, move to the previous row or column
      if (dp[i][k][j] == dp[i - 1][k][j]) {
        i--;
      } else {
        j--;
      }
    }
  }

  // Output
  printf("%d\n", dp[N][K][N]);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%c", chosen[i][j]);
    }
    printf("\n");
  }

  return 0;
}
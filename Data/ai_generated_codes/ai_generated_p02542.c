#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define MAX_M 50

int N, M;
char board[MAX_N][MAX_M + 1];

int solve() {
  int dp[MAX_N][MAX_M];
  memset(dp, 0, sizeof(dp));

  // Initialize the DP table for the last row and column
  for (int i = N - 1; i >= 0; i--) {
    for (int j = M - 1; j >= 0; j--) {
      if (board[i][j] == 'o') {
        // Check if we can move the piece right or down
        if (j + 1 < M && board[i][j + 1] == '.') {
          dp[i][j] = 1 + dp[i][j + 1];
        }
        if (i + 1 < N && board[i + 1][j] == '.') {
          dp[i][j] = (dp[i][j] > dp[i + 1][j] + 1) ? dp[i][j] : dp[i + 1][j] + 1;
        }
      }
    }
  }

  // Find the maximum number of operations from the top-left corner
  return dp[0][0];
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", board[i]);
  }

  int max_operations = solve();
  printf("%d\n", max_operations);

  return 0;
}
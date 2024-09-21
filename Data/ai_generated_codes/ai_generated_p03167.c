#include <stdio.h>

#define MOD 1000000007

int main() {
  int H, W;
  scanf("%d %d", &H, &W);

  // grid[i][j] = 1 if (i, j) is an empty square, otherwise 0
  int grid[1001][1001] = {0};

  // Read the grid from standard input
  char a[1001][1001];
  for (int i = 1; i <= H; i++) {
    scanf("%s", a[i] + 1); // +1 to skip the newline character
    for (int j = 1; j <= W; j++) {
      if (a[i][j] == '.') {
        grid[i][j] = 1;
      }
    }
  }

  // Dynamic programming approach
  // dp[i][j] represents the number of paths to reach (i, j)
  long long dp[1001][1001] = {0};

  // Initialize the starting point
  dp[1][1] = 1;

  // Iterate through the grid
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (grid[i][j] == 1) {
        // If the square is empty, it can be reached from the square above or the square to the left
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      }
    }
  }

  // Print the result
  printf("%lld\n", dp[H][W]);

  return 0;
}
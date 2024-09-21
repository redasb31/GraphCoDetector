#include <stdio.h>

#define MOD 1000000007

long long dp[101][8][8];

// Function to calculate the number of valid Amidakuji patterns
long long countAmidakuji(int H, int W, int K) {
  // Base case: No horizontal lines
  for (int i = 1; i <= W; i++) {
    dp[0][i][i] = 1;
  }

  // Iterate through heights
  for (int h = 1; h <= H; h++) {
    // Iterate through columns
    for (int w = 1; w <= W; w++) {
      // Iterate through destination columns
      for (int k = 1; k <= W; k++) {
        // Case 1: No horizontal line from current column
        dp[h][w][k] = (dp[h][w][k] + dp[h - 1][w][k]) % MOD;

        // Case 2: Horizontal line from current column to the left
        if (w > 1) {
          dp[h][w][k] = (dp[h][w][k] + dp[h - 1][w - 1][k]) % MOD;
        }

        // Case 3: Horizontal line from current column to the right
        if (w < W) {
          dp[h][w][k] = (dp[h][w][k] + dp[h - 1][w + 1][k]) % MOD;
        }
      }
    }
  }

  return dp[H][K][K];
}

int main() {
  int H, W, K;
  scanf("%d %d %d", &H, &W, &K);

  long long result = countAmidakuji(H, W, K);
  printf("%lld\n", result);

  return 0;
}
#include <stdio.h>

#define MAX_N 10000
#define MAX_M 10000

int main() {
  int C, N, M;
  int s[MAX_N], p[MAX_N];
  int dp[MAX_M + 1][MAX_N + 1]; // dp[k][i]: max price for k children with gifts up to i-th kind

  // Input
  scanf("%d %d %d", &C, &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &s[i], &p[i]);
  }

  // Initialization
  for (int k = 0; k <= M; k++) {
    for (int i = 0; i <= N; i++) {
      dp[k][i] = 0;
    }
  }

  // DP calculation
  for (int k = 1; k <= M; k++) {
    for (int i = 1; i <= N; i++) {
      // Choose the i-th gift for all k children
      if (s[i] * k <= C) {
        dp[k][i] = dp[k][i - 1] + p[i] * k;
      } else {
        // Do not choose the i-th gift
        dp[k][i] = dp[k][i - 1];
      }
      // Find the maximum price with or without the i-th gift
      dp[k][i] = (dp[k][i] > dp[k][i - 1]) ? dp[k][i] : dp[k][i - 1];
    }
  }

  // Output
  for (int k = 1; k <= M; k++) {
    printf("%d\n", dp[k][N]);
  }

  return 0;
}
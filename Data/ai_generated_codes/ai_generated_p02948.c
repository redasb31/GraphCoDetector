#include <stdio.h>

#define MAX_N 100000
#define MAX_M 100000

int main() {
  // Input:
  // N: Number of jobs
  // M: Maximum days to complete jobs
  int N, M;
  scanf("%d %d", &N, &M);

  // Input:
  // A_i: Number of days to complete the i-th job
  // B_i: Reward for completing the i-th job
  int A[MAX_N], B[MAX_N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }

  // DP table:
  // dp[i][j]: Maximum reward achievable in j days using jobs from 0 to i
  int dp[MAX_N + 1][MAX_M + 1];

  // Initialize DP table
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j] = 0;
    }
  }

  // Calculate maximum reward for each day and job combination
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      // If job can be completed within current day
      if (j >= A[i - 1]) {
        // Choose maximum reward: 
        // 1. Include current job and continue from previous job
        // 2. Exclude current job and use the best reward from previous day
        dp[i][j] =
            dp[i - 1][j - A[i - 1]] + B[i - 1];  // Include current job
        dp[i][j] =
            dp[i][j] > dp[i - 1][j] ? dp[i][j] : dp[i - 1][j];  // Exclude
      } else {
        // Current job cannot be completed within current day
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Maximum reward achievable in M days
  int max_reward = dp[N][M];
  printf("%d\n", max_reward);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 80
#define MAX_M 320

typedef struct {
  int x, y, v;
} Jewel;

typedef struct {
  char t;
  int a, b;
} Condition;

int main() {
  // Input variables
  int N, M;
  Jewel jewels[MAX_N];
  Condition conditions[MAX_M];

  // Read input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &jewels[i].x, &jewels[i].y, &jewels[i].v);
  }
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf(" %c %d %d", &conditions[i].t, &conditions[i].a, &conditions[i].b);
  }

  // Create a 2D array to store the dp values
  // dp[i][j] represents the maximum value of jewels that can be stolen
  // considering only the first i jewels and up to j conditions
  long long dp[MAX_N + 1][MAX_M + 1];

  // Initialize dp array
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j] = 0;
    }
  }

  // Iterate through each jewel and each condition
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      // If no condition is considered, take the current jewel
      if (j == 0) {
        dp[i][j] = dp[i - 1][j] + jewels[i - 1].v;
      } else {
        // Consider the previous dp value
        dp[i][j] = dp[i - 1][j];

        // Check if the current jewel can be stolen according to the current condition
        if (conditions[j - 1].t == 'L' && jewels[i - 1].x <= conditions[j - 1].a && dp[i - 1][j - 1] + jewels[i - 1].v >= dp[i][j] && dp[i - 1][j - 1] <= conditions[j - 1].b) {
          dp[i][j] = dp[i - 1][j - 1] + jewels[i - 1].v;
        } else if (conditions[j - 1].t == 'R' && jewels[i - 1].x >= conditions[j - 1].a && dp[i - 1][j - 1] + jewels[i - 1].v >= dp[i][j] && dp[i - 1][j - 1] <= conditions[j - 1].b) {
          dp[i][j] = dp[i - 1][j - 1] + jewels[i - 1].v;
        } else if (conditions[j - 1].t == 'D' && jewels[i - 1].y <= conditions[j - 1].a && dp[i - 1][j - 1] + jewels[i - 1].v >= dp[i][j] && dp[i - 1][j - 1] <= conditions[j - 1].b) {
          dp[i][j] = dp[i - 1][j - 1] + jewels[i - 1].v;
        } else if (conditions[j - 1].t == 'U' && jewels[i - 1].y >= conditions[j - 1].a && dp[i - 1][j - 1] + jewels[i - 1].v >= dp[i][j] && dp[i - 1][j - 1] <= conditions[j - 1].b) {
          dp[i][j] = dp[i - 1][j - 1] + jewels[i - 1].v;
        }
      }
    }
  }

  // Print the maximum value
  printf("%lld\n", dp[N][M]);

  return 0;
}
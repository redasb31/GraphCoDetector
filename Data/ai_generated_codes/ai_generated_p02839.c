#include <stdio.h>
#include <stdlib.h>

#define MAX_H 80
#define MAX_W 80

int main() {
  int H, W;
  int A[MAX_H][MAX_W];
  int B[MAX_H][MAX_W];
  int dp[MAX_H][MAX_W][2]; // dp[i][j][0] -> sum of red numbers, dp[i][j][1] -> sum of blue numbers

  // Input
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  // Initialization
  dp[0][0][0] = A[0][0]; 
  dp[0][0][1] = B[0][0];

  // Dynamic Programming
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      // Base cases (first row and first column)
      if (i == 0 && j == 0) continue;

      // Move from (i-1, j)
      dp[i][j][0] =  dp[i - 1][j][0] + A[i][j];
      dp[i][j][1] =  dp[i - 1][j][1] + B[i][j];
      
      // Move from (i, j-1)
      if (j > 0) {
        int temp0 = dp[i][j - 1][0] + A[i][j];
        int temp1 = dp[i][j - 1][1] + B[i][j];
        if (abs(temp0 - temp1) < abs(dp[i][j][0] - dp[i][j][1])) {
          dp[i][j][0] = temp0;
          dp[i][j][1] = temp1;
        }
      }
    }
  }

  // Find the minimum unbalancedness
  int minUnbalancedness = abs(dp[H - 1][W - 1][0] - dp[H - 1][W - 1][1]);
  printf("%d\n", minUnbalancedness);

  return 0;
}
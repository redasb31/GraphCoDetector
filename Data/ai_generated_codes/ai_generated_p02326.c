#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input the dimensions of the matrix
  int H, W;
  scanf("%d %d", &H, &W);

  // Allocate memory for the matrix
  int **matrix = (int **)malloc(H * sizeof(int *));
  for (int i = 0; i < H; i++) {
    matrix[i] = (int *)malloc(W * sizeof(int));
  }

  // Input the matrix elements
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  // Initialize a 2D array to store the size of the largest square
  // ending at each cell
  int **dp = (int **)malloc(H * sizeof(int *));
  for (int i = 0; i < H; i++) {
    dp[i] = (int *)malloc(W * sizeof(int));
  }

  // Initialize the first row and column of dp
  for (int i = 0; i < H; i++) {
    dp[i][0] = matrix[i][0];
  }
  for (int j = 0; j < W; j++) {
    dp[0][j] = matrix[0][j];
  }

  // Calculate the size of the largest square ending at each cell
  int max_area = 0;
  for (int i = 1; i < H; i++) {
    for (int j = 1; j < W; j++) {
      if (matrix[i][j] == 0) {
        dp[i][j] = 1 + (int)fmin(dp[i - 1][j], fmin(dp[i][j - 1], dp[i - 1][j - 1]));
      } else {
        dp[i][j] = 0;
      }
      max_area = (int)fmax(max_area, dp[i][j] * dp[i][j]);
    }
  }

  // Print the maximum area
  printf("%d\n", max_area);

  // Free allocated memory
  for (int i = 0; i < H; i++) {
    free(matrix[i]);
    free(dp[i]);
  }
  free(matrix);
  free(dp);

  return 0;
}
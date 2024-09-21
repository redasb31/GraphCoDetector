#include <stdio.h>
#include <math.h>

int main() {
  // Read input values for N and M.
  int N, M;
  scanf("%d %d", &N, &M);

  // Calculate the dimensions of the grid.
  int rows = pow(2, N) - 1;
  int cols = pow(2, M) - 1;

  // Initialize the grid with all 1s.
  // This ensures that the sum of any rectangular subgrid will be odd.
  int grid[rows][cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = 1;
    }
  }

  // Print the grid.
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d", grid[i][j]);
      if (j != cols - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
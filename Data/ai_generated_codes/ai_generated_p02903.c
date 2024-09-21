#include <stdio.h>

int main() {
  int H, W, A, B;

  // Read input
  scanf("%d %d %d %d", &H, &W, &A, &B);

  // Check if the conditions are satisfiable
  if (2 * A > W || 2 * B > H) {
    printf("-1\n");
    return 0;
  }

  // Create a grid to store the values
  int grid[H][W];

  // Fill the grid
  int row = 0;
  int col = 0;
  for (int i = 0; i < H * W; i++) {
    // Fill the grid with 0s and 1s in a alternating pattern
    grid[row][col] = i % 2;

    // Move to the next cell
    col++;
    if (col == W) {
      col = 0;
      row++;
    }
  }

  // Print the grid
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%d", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}
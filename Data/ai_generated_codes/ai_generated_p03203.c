#include <stdio.h>

int main() {
  // Declare variables for grid dimensions, number of obstacles, and coordinates
  int H, W, N;
  scanf("%d %d %d", &H, &W, &N);

  // Declare a 2D array to represent the grid, with 1 for obstacles and 0 for empty cells
  int grid[H + 1][W + 1];
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      grid[i][j] = 0;
    }
  }

  // Set obstacles in the grid
  int X, Y;
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &X, &Y);
    grid[X][Y] = 1;
  }

  // Initialize the piece's position
  int x = 1, y = 1;

  // Track the number of actions Takahashi takes
  int actions = 0;

  // Game loop: continue until the piece doesn't move twice in a row
  while (1) {
    // Takahashi's turn
    actions++;

    // Check if Takahashi can move right
    if (y + 1 <= W && grid[x][y + 1] == 0) {
      y++;
    } else {
      // If Takahashi can't move, check if Aoki can move down
      if (x + 1 <= H && grid[x + 1][y] == 0) {
        // If Aoki can move, it's Takahashi's turn again
        actions++;
        x++;
      } else {
        // If both players can't move, the game ends
        break;
      }
    }
  }

  // Print the number of actions Takahashi took
  printf("%d\n", actions);

  return 0;
}
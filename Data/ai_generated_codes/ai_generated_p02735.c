#include <stdio.h>

#define MAX_H 100
#define MAX_W 100

int H, W;
char grid[MAX_H + 1][MAX_W + 1];

// Function to invert the color of a rectangular area in the grid
void invert_area(int r0, int c0, int r1, int c1) {
  for (int r = r0; r <= r1; r++) {
    for (int c = c0; c <= c1; c++) {
      if (grid[r][c] == '#') {
        grid[r][c] = '.';
      } else {
        grid[r][c] = '#';
      }
    }
  }
}

// Function to calculate the minimum number of operations required
int solve() {
  int operations = 0;
  // Iterate through the grid from top-left to bottom-right
  for (int r = 1; r <= H; r++) {
    for (int c = 1; c <= W; c++) {
      // If the current square is black, invert the area from (r, c) to (H, W)
      if (grid[r][c] == '#') {
        invert_area(r, c, H, W);
        operations++;
      }
    }
  }
  return operations;
}

int main() {
  // Read input from standard input
  scanf("%d %d\n", &H, &W);
  for (int r = 1; r <= H; r++) {
    scanf("%s\n", grid[r] + 1);
  }

  // Calculate and print the minimum number of operations
  printf("%d\n", solve());

  return 0;
}
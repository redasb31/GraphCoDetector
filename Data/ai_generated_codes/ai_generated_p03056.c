#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 185

int complexity(char grid[][MAX_SIZE], int h, int w, int row_start, int row_end, int col_start, int col_end) {
  // Base case: If all squares are the same color
  if (row_start == row_end || col_start == col_end) {
    int same_color = 1;
    for (int i = row_start; i < row_end; i++) {
      for (int j = col_start; j < col_end; j++) {
        if (grid[i][j] != grid[row_start][col_start]) {
          same_color = 0;
          break;
        }
      }
    }
    if (same_color) {
      return 0;
    }
  }

  // Recursive case: Divide the grid into two subgrids
  int min_complexity = MAX_SIZE;
  // Divide horizontally
  for (int i = row_start + 1; i < row_end; i++) {
    int c1 = complexity(grid, h, w, row_start, i, col_start, col_end);
    int c2 = complexity(grid, h, w, i, row_end, col_start, col_end);
    min_complexity = (c1 > c2 ? c1 : c2);
    if (min_complexity < MAX_SIZE) {
      break;
    }
  }

  // Divide vertically
  for (int i = col_start + 1; i < col_end; i++) {
    int c1 = complexity(grid, h, w, row_start, row_end, col_start, i);
    int c2 = complexity(grid, h, w, row_start, row_end, i, col_end);
    min_complexity = (c1 > c2 ? c1 : c2);
    if (min_complexity < MAX_SIZE) {
      break;
    }
  }

  // Return the complexity of the grid
  return min_complexity + 1;
}

int main() {
  int h, w;
  scanf("%d %d", &h, &w);

  // Read the grid
  char grid[MAX_SIZE][MAX_SIZE];
  for (int i = 0; i < h; i++) {
    scanf("%s", grid[i]);
  }

  // Calculate and print the complexity
  printf("%d\n", complexity(grid, h, w, 0, h, 0, w));

  return 0;
}
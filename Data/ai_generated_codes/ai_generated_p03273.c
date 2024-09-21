#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
  int H, W;
  char grid[MAX_SIZE][MAX_SIZE];
  int row_count[MAX_SIZE] = {0}; // Count of black squares in each row
  int col_count[MAX_SIZE] = {0}; // Count of black squares in each column
  int i, j, row_to_remove, col_to_remove;

  // Read grid dimensions
  scanf("%d %d", &H, &W);

  // Read grid data
  for (i = 0; i < H; i++) {
    scanf("%s", grid[i]);
    for (j = 0; j < W; j++) {
      if (grid[i][j] == '#') {
        row_count[i]++;
        col_count[j]++;
      }
    }
  }

  // Repeatedly remove rows/columns with all white squares
  while (1) {
    row_to_remove = -1;
    col_to_remove = -1;

    // Find a row with all white squares
    for (i = 0; i < H; i++) {
      if (row_count[i] == 0) {
        row_to_remove = i;
        break;
      }
    }

    // Find a column with all white squares
    for (j = 0; j < W; j++) {
      if (col_count[j] == 0) {
        col_to_remove = j;
        break;
      }
    }

    // If no row or column can be removed, break
    if (row_to_remove == -1 && col_to_remove == -1) {
      break;
    }

    // Remove the row or column
    if (row_to_remove != -1) {
      // Shift rows down
      for (i = row_to_remove; i < H - 1; i++) {
        for (j = 0; j < W; j++) {
          grid[i][j] = grid[i + 1][j];
        }
      }
      // Update row counts
      for (i = row_to_remove; i < H - 1; i++) {
        row_count[i] = row_count[i + 1];
      }
      // Update column counts
      for (j = 0; j < W; j++) {
        if (grid[H - 1][j] == '#') {
          col_count[j]++;
        }
      }
      H--; // Decrement number of rows
    } else {
      // Shift columns right
      for (i = 0; i < H; i++) {
        for (j = col_to_remove; j < W - 1; j++) {
          grid[i][j] = grid[i][j + 1];
        }
      }
      // Update column counts
      for (i = 0; i < H; i++) {
        if (grid[i][W - 1] == '#') {
          row_count[i]++;
        }
      }
      // Update row counts
      for (j = col_to_remove; j < W - 1; j++) {
        col_count[j] = col_count[j + 1];
      }
      W--; // Decrement number of columns
    }
  }

  // Print the final grid
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to check if a square is valid
int isValid(int row, int col, int h, int w) {
  return (row >= 0 && row < h && col >= 0 && col < w);
}

// Function to perform Depth First Search (DFS) to count connected components
int dfs(char **grid, int row, int col, int h, int w, char color) {
  if (!isValid(row, col, h, w) || grid[row][col] != color) {
    return 0;
  }
  // Mark the current square as visited
  grid[row][col] = '#';
  // Explore adjacent squares
  int count = 1;
  count += dfs(grid, row + 1, col, h, w, color);
  count += dfs(grid, row - 1, col, h, w, color);
  count += dfs(grid, row, col + 1, h, w, color);
  count += dfs(grid, row, col - 1, h, w, color);
  return count;
}

int main() {
  int A, B;
  // Read the number of white and black connected components
  scanf("%d %d", &A, &B);

  // Calculate the dimensions of the grid
  int h = (A + B) / 2; // Height
  int w = (A + B) / 2 + (A + B) % 2; // Width

  // Allocate memory for the grid
  char **grid = (char **)malloc(h * sizeof(char *));
  for (int i = 0; i < h; i++) {
    grid[i] = (char *)malloc((w + 1) * sizeof(char));
  }

  // Initialize the grid with '.' (white)
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      grid[i][j] = '.';
    }
    grid[i][w] = '\0'; // Add null terminator for string output
  }

  // Create white connected components
  int whiteComponents = 0;
  int row = 0;
  int col = 0;
  while (whiteComponents < A) {
    if (grid[row][col] == '.') {
      whiteComponents += dfs(grid, row, col, h, w, '.');
    }
    // Move to the next square in a spiral pattern
    col++;
    if (col == w) {
      col = 0;
      row++;
    }
  }

  // Create black connected components
  int blackComponents = 0;
  row = 0;
  col = 0;
  while (blackComponents < B) {
    if (grid[row][col] == '.') {
      blackComponents += dfs(grid, row, col, h, w, '#');
    }
    // Move to the next square in a spiral pattern
    col++;
    if (col == w) {
      col = 0;
      row++;
    }
  }

  // Print the grid dimensions
  printf("%d %d\n", h, w);

  // Print the grid
  for (int i = 0; i < h; i++) {
    printf("%s\n", grid[i]);
  }

  // Free allocated memory
  for (int i = 0; i < h; i++) {
    free(grid[i]);
  }
  free(grid);

  return 0;
}
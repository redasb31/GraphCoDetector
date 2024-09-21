#include <stdio.h>
#include <stdlib.h>

// Function to create a grid of specified size
char **createGrid(int h, int w) {
  char **grid = (char **)malloc(sizeof(char *) * h);
  for (int i = 0; i < h; i++) {
    grid[i] = (char *)malloc(sizeof(char) * (w + 1)); // +1 for null terminator
    for (int j = 0; j < w; j++) {
      grid[i][j] = '.'; // Initialize all squares to white
    }
    grid[i][w] = '\0'; // Add null terminator for string operations
  }
  return grid;
}

// Function to paint a square black
void paintBlack(char **grid, int h, int w, int row, int col) {
  grid[row][col] = '#';
}

// Function to check if a square is within the grid bounds
int isValidSquare(int h, int w, int row, int col) {
  return (row >= 0 && row < h && col >= 0 && col < w);
}

// Function to perform Depth First Search (DFS) to color connected components
void dfs(char **grid, int h, int w, int row, int col, char color) {
  if (!isValidSquare(h, w, row, col) || grid[row][col] != '.') {
    return;
  }

  grid[row][col] = color;

  // Explore adjacent squares
  dfs(grid, h, w, row + 1, col, color);
  dfs(grid, h, w, row - 1, col, color);
  dfs(grid, h, w, row, col + 1, color);
  dfs(grid, h, w, row, col - 1, color);
}

// Function to create the grid with specified number of connected components
void createGridWithComponents(int h, int w, int A, int B) {
  char **grid = createGrid(h, w);
  int componentCount = 0;
  char color = 'W';

  // Paint squares to create connected components
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '.') {
        componentCount++;
        dfs(grid, h, w, i, j, color);
        if (componentCount == A) {
          color = 'B'; // Switch to painting black
        }
      }
    }
  }

  // Print the grid
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    printf("%s\n", grid[i]);
  }

  // Free allocated memory
  for (int i = 0; i < h; i++) {
    free(grid[i]);
  }
  free(grid);
}

int main() {
  int A, B;

  scanf("%d %d", &A, &B);

  // Set grid size to ensure at least A + B connected components
  int h = (A + B) / 2; // Approximate height for minimum size
  int w = 2;             // Minimum width to have multiple columns

  // Adjust grid size if required
  if (h * w < A + B) {
    h++;
  }

  // Create and print the grid with specified components
  createGridWithComponents(h, w, A, B);

  return 0;
}
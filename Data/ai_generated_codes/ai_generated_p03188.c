#include <stdio.h>

int main() {
  int K; // Number of colors

  // Input the number of colors
  scanf("%d", &K);

  // Determine the size of the grid (n x n)
  int n = K; // Initialize n to K

  // If K is 1, we need a grid of size 1
  if (K == 1) {
    n = 1;
  } else if (K <= 3) {
    // For K <= 3, a 3 x 3 grid is sufficient
    n = 3;
  } else {
    // For larger K, ensure n is at least K
    n = K; 
  }

  // Output the size of the grid
  printf("%d\n", n);

  // Create a 2D array to represent the grid
  int grid[n][n];

  // Coloring the grid based on K
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // Assign colors in a spiral pattern
      grid[i][j] = (i * n + j) % K + 1; 
    }
  }

  // Output the grid coloring
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}
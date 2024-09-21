#include <stdio.h>

// Define the maximum size of the panel grid
#define MAX_H 8
#define MAX_W 8

// Define the number of colors
#define NUM_COLORS 6

// Structure to represent a panel
typedef struct {
  int color;
  int fused; // Flag to indicate if the panel is fused with others
} Panel;

// Function to find the size of the largest united panel with the target color
int findLargestUnitedPanel(Panel grid[MAX_H][MAX_W], int h, int w, int target_color);

int main() {
  int h, w, c;
  Panel grid[MAX_H][MAX_W];

  // Read input until three zeros are encountered
  while (scanf("%d %d %d", &h, &w, &c) != EOF && (h != 0 || w != 0 || c != 0)) {
    // Read panel colors
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &grid[i][j].color);
        grid[i][j].fused = 0;
      }
    }

    // Find the size of the largest united panel
    int max_size = findLargestUnitedPanel(grid, h, w, c);

    // Print the output
    printf("%d\n", max_size);
  }

  return 0;
}

// Function to find the size of the largest united panel with the target color
int findLargestUnitedPanel(Panel grid[MAX_H][MAX_W], int h, int w, int target_color) {
  // Start with the panel at the upper left corner
  int i = 0, j = 0;

  // Initialize the size of the united panel to 1
  int size = 1;

  // Iterate through five color changes
  for (int k = 0; k < 5; k++) {
    // Change the color of the panel
    grid[i][j].color = target_color;

    // Fuse adjacent panels of the same color
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (i + di >= 0 && i + di < h && j + dj >= 0 && j + dj < w &&
            grid[i + di][j + dj].color == target_color && !grid[i + di][j + dj].fused) {
          grid[i + di][j + dj].fused = 1;
          size++;
        }
      }
    }
  }

  // Return the size of the united panel
  return size;
}
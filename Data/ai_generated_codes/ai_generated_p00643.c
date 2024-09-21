#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

int grid[MAX_SIZE][MAX_SIZE];
int h, w;
int start_row, start_col;
int dest_row, dest_col;

// Function to calculate the penalty for rolling the dice
int calculate_penalty(int row, int col, int face) {
  return grid[row][col] * face;
}

// Function to calculate the minimum penalty for moving the dice from
// the starting cell to the destination cell
int min_penalty(int row, int col, int face) {
  // Base case: if we have reached the destination cell, return the penalty
  if (row == dest_row && col == dest_col) {
    return calculate_penalty(row, col, face);
  }

  // Initialize the minimum penalty to infinity
  int min_penalty = INT_MAX;

  // Explore all possible moves
  // Move north (face 5)
  if (row > 0) {
    min_penalty =  min(min_penalty, min_penalty(row - 1, col, 5) + calculate_penalty(row, col, 5));
  }
  // Move south (face 2)
  if (row < h - 1) {
    min_penalty = min(min_penalty, min_penalty(row + 1, col, 2) + calculate_penalty(row, col, 2));
  }
  // Move east (face 3)
  if (col < w - 1) {
    min_penalty = min(min_penalty, min_penalty(row, col + 1, 3) + calculate_penalty(row, col, 3));
  }
  // Move west (face 4)
  if (col > 0) {
    min_penalty = min(min_penalty, min_penalty(row, col - 1, 4) + calculate_penalty(row, col, 4));
  }

  return min_penalty;
}

int main() {
  while (1) {
    // Read input
    scanf("%d %d", &h, &w);
    if (h == 0 && w == 0) {
      break;
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &grid[i][j]);
      }
    }
    scanf("%d %d", &start_row, &start_col);
    scanf("%d %d", &dest_row, &dest_col);

    // Calculate the minimum penalty
    int penalty = min_penalty(start_row, start_col, 1);

    // Print the output
    printf("%d\n", penalty);
  }
  return 0;
}
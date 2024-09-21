#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 400
#define MAX_W 400

int main() {
  // Input:
  int H, W;
  char S[MAX_H][MAX_W + 1];

  // Input the grid dimensions
  scanf("%d %d", &H, &W);

  // Input the grid as strings
  for (int i = 0; i < H; i++) {
    scanf("%s", S[i]);
  }

  // Initialize a 2D array to store the number of paths from each black cell
  int paths[MAX_H][MAX_W];
  memset(paths, 0, sizeof(paths));

  // Iterate through the grid and count paths for each black cell
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') {
        // Check if the cell above is white
        if (i > 0 && S[i - 1][j] == '.') {
          paths[i][j] += paths[i - 1][j];
        }
        // Check if the cell below is white
        if (i < H - 1 && S[i + 1][j] == '.') {
          paths[i][j] += paths[i + 1][j];
        }
        // Check if the cell to the left is white
        if (j > 0 && S[i][j - 1] == '.') {
          paths[i][j] += paths[i][j - 1];
        }
        // Check if the cell to the right is white
        if (j < W - 1 && S[i][j + 1] == '.') {
          paths[i][j] += paths[i][j + 1];
        }
        // Add 1 for the path starting at the current cell
        paths[i][j]++;
      }
    }
  }

  // Count the total number of pairs
  long long count = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      // If the cell is black, add the number of paths from it to the total count
      if (S[i][j] == '#') {
        count += paths[i][j];
      }
    }
  }

  // Print the total count
  printf("%lld\n", count);

  return 0;
}
#include <stdio.h>

int main() {
  int H, W, i, j, k, maxArea = 0;
  int matrix[1400][1400];

  // Read the input
  scanf("%d %d", &H, &W);
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  // Iterate through each cell as the bottom-left corner of the rectangle
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      // If the current cell is 1, skip it
      if (matrix[i][j] == 1) {
        continue;
      }

      // Calculate the maximum height and width of the rectangle
      int height = 1, width = 1;
      for (k = i + 1; k < H && matrix[k][j] == 0; k++) {
        height++;
      }
      for (k = j + 1; k < W && matrix[i][k] == 0; k++) {
        width++;
      }

      // Calculate the area of the current rectangle
      int area = height * width;

      // Update the maximum area
      maxArea = (area > maxArea) ? area : maxArea;
    }
  }

  // Print the maximum area
  printf("%d\n", maxArea);

  return 0;
}
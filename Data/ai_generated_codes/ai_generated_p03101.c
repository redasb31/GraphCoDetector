#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int H, W, h, w;

  // Read the input values from the user
  scanf("%d %d\n", &H, &W);
  scanf("%d %d\n", &h, &w);

  // Calculate the number of white cells remaining
  // We subtract the number of cells in the chosen rows and columns
  // from the total number of cells. We need to be careful not to
  // double-count the cells that are in both a chosen row and column
  int white_cells = H * W - (h * W + w * H - h * w);

  // Print the result
  printf("%d\n", white_cells);

  return 0;
}
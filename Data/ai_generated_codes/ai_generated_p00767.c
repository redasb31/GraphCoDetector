#include <stdio.h>

int main() {
  int h, w;

  // Loop through each dataset
  while (1) {
    scanf("%d %d", &h, &w);

    // End of input
    if (h == 0 && w == 0) {
      break;
    }

    // Find the smallest bigger rectangle
    int next_h = h;
    int next_w = w;
    while (1) {
      // Calculate the square of the diagonal length of the current rectangle
      int current_diagonal_square = h * h + w * w;

      // Calculate the square of the diagonal length of the next rectangle
      int next_diagonal_square = next_h * next_h + next_w * next_w;

      // If the current rectangle's diagonal length is smaller than the next one's
      if (current_diagonal_square < next_diagonal_square) {
        break;
      }

      // Otherwise, try increasing the width
      next_w++;

      // If the width is greater than 150, try increasing the height
      if (next_w > 150) {
        next_h++;
        next_w = next_h + 1; // Ensure width is greater than height
      }
    }

    // Print the result
    printf("%d %d\n", next_h, next_w);
  }

  return 0;
}
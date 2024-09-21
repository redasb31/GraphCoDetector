#include <stdio.h>

int main() {
  int H, W; // Height and width of the chessboard
  
  // Loop until the input is 0 0
  while (1) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0) {
      break; 
    }

    // Loop through each row of the chessboard
    for (int i = 0; i < H; i++) {
      // Loop through each column of the chessboard
      for (int j = 0; j < W; j++) {
        // Print '#' if the sum of row and column is even, otherwise print '.'
        if ((i + j) % 2 == 0) {
          printf("#");
        } else {
          printf(".");
        }
      }
      // Print a newline after each row
      printf("\n");
    }

    // Print a blank line after each dataset
    printf("\n");
  }

  return 0;
}
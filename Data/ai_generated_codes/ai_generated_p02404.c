#include <stdio.h>

int main() {
  int H, W;

  // Loop through each dataset until H and W are both 0
  while (1) {
    scanf("%d %d", &H, &W);

    // If both H and W are 0, break the loop
    if (H == 0 && W == 0) {
      break;
    }

    // Print the top row of the frame
    for (int i = 0; i < W; i++) {
      printf("#");
    }
    printf("\n");

    // Print the middle rows of the frame
    for (int i = 1; i < H - 1; i++) {
      printf("#");
      for (int j = 1; j < W - 1; j++) {
        printf(".");
      }
      printf("#\n");
    }

    // Print the bottom row of the frame
    for (int i = 0; i < W; i++) {
      printf("#");
    }
    printf("\n\n"); // Print a blank line after each dataset
  }

  return 0;
}
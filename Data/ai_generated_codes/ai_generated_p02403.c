#include <stdio.h>

int main() {
  int H, W;

  // Loop through each dataset
  while (1) {
    scanf("%d %d", &H, &W);

    // Exit if both H and W are 0
    if (H == 0 && W == 0) {
      break;
    }

    // Print the rectangle
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        printf("#");
      }
      printf("\n");
    }

    // Print a blank line after each dataset
    printf("\n");
  }

  return 0;
}
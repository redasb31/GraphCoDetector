#include <stdio.h>

int main() {
  // Loop through each number from 1 to 9
  for (int i = 1; i <= 9; i++) {
    // Loop through each multiplier from 1 to 9
    for (int j = 1; j <= 9; j++) {
      // Print the multiplication equation
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }

  return 0;
}
#include <stdio.h>

int main() {
  // Declare a 2D character array to store the grid
  char grid[3][3];

  // Read the input grid
  for (int i = 0; i < 3; i++) {
    scanf("%s", grid[i]);
  }

  // Print the diagonal string
  printf("%c%c%c\n", grid[0][0], grid[1][1], grid[2][2]);

  return 0;
}
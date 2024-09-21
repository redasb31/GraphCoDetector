#include <stdio.h>

int main() {
  // Declare the radius of the circle
  int r;

  // Read the radius from the standard input
  scanf("%d", &r);

  // Calculate the area of the regular dodecagon
  int area = 3 * r * r;

  // Print the area of the regular dodecagon
  printf("%d\n", area);

  return 0;
}
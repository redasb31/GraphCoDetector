#include <stdio.h>

int main() {
  // Input the coordinates of two vertices
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  // Calculate the side length of the square
  int side = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
  side = sqrt(side);

  // Calculate the coordinates of the other two vertices
  int x3 = x2 + (y2 - y1); // (x2, y2) + (0, side)
  int y3 = y2 - (x2 - x1); // (x2, y2) + (-side, 0)
  int x4 = x1 + (y2 - y1); // (x1, y1) + (0, side)
  int y4 = y1 - (x2 - x1); // (x1, y1) + (-side, 0)

  // Output the coordinates of the other two vertices
  printf("%d %d %d %d\n", x3, y3, x4, y4);

  return 0;
}
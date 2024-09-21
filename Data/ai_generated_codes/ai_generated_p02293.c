#include <stdio.h>

int main() {
  int q, xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
  scanf("%d", &q); // Read the number of queries

  // Loop through each query
  while (q--) {
    scanf("%d %d %d %d %d %d %d %d", 
          &xp0, &yp0, &xp1, &yp1, &xp2, &yp2, &xp3, &yp3);

    // Calculate the direction vectors of the lines
    int dx1 = xp1 - xp0, dy1 = yp1 - yp0;
    int dx2 = xp3 - xp2, dy2 = yp3 - yp2;

    // Calculate the dot product of the direction vectors
    int dot_product = dx1 * dx2 + dy1 * dy2;

    // Determine the relationship between the lines
    if (dot_product == 0) {
      // Parallel lines
      printf("2\n");
    } else if (dx1 * dy2 == -dy1 * dx2) {
      // Orthogonal lines
      printf("1\n");
    } else {
      // Neither parallel nor orthogonal
      printf("0\n");
    }
  }

  return 0;
}
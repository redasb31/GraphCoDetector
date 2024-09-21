#include <stdio.h>

// Function to calculate the cross product of two vectors
int crossProduct(int x1, int y1, int x2, int y2) {
  return x1 * y2 - x2 * y1;
}

// Function to check if two segments intersect
int checkIntersection(int xp0, int yp0, int xp1, int yp1, int xp2, int yp2, int xp3, int yp3) {
  // Calculate the cross products to determine if the segments intersect
  int c1 = crossProduct(xp1 - xp0, yp1 - yp0, xp2 - xp0, yp2 - yp0);
  int c2 = crossProduct(xp1 - xp0, yp1 - yp0, xp3 - xp0, yp3 - yp0);
  int c3 = crossProduct(xp3 - xp2, yp3 - yp2, xp0 - xp2, yp0 - yp2);
  int c4 = crossProduct(xp3 - xp2, yp3 - yp2, xp1 - xp2, yp1 - yp2);

  // If the cross products have opposite signs, the segments intersect
  if ((c1 * c2 < 0) && (c3 * c4 < 0)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int q, xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;

  // Read the number of queries
  scanf("%d", &q);

  // Process each query
  for (int i = 0; i < q; i++) {
    // Read the coordinates of the end points of the segments
    scanf("%d %d %d %d %d %d %d %d", &xp0, &yp0, &xp1, &yp1, &xp2, &yp2, &xp3, &yp3);

    // Check if the segments intersect and print the result
    printf("%d\n", checkIntersection(xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3));
  }

  return 0;
}
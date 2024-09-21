#include <stdio.h>
#include <math.h>

int main() {
  int c1x, c1y, c1r, c2x, c2y, c2r;

  // Read the input values for the circles
  scanf("%d %d %d", &c1x, &c1y, &c1r);
  scanf("%d %d %d", &c2x, &c2y, &c2r);

  // Calculate the distance between the centers of the circles
  double distance = sqrt(pow(c1x - c2x, 2) + pow(c1y - c2y, 2));

  // Determine the number of common tangent lines
  int numTangents;
  if (distance > c1r + c2r) {
    numTangents = 4; // No intersection
  } else if (distance == c1r + c2r) {
    numTangents = 3; // Circumscribed
  } else if (distance < c1r + c2r && distance > abs(c1r - c2r)) {
    numTangents = 2; // Intersecting
  } else if (distance == abs(c1r - c2r)) {
    numTangents = 1; // Inscribed
  } else {
    numTangents = 0; // One circle includes the other
  }

  // Print the number of common tangent lines
  printf("%d\n", numTangents);

  return 0;
}
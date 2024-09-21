#include <stdio.h>

int main() {
  int X; // Angle of rotation in degrees

  // Input the angle of rotation
  scanf("%d", &X);

  // Calculate the number of rotations needed to complete a full circle (360 degrees)
  int K = 360 / (360 - X); // K is the smallest positive integer that satisfies (360 - X) * K = 360

  // Print the result
  printf("%d\n", K);

  return 0;
}
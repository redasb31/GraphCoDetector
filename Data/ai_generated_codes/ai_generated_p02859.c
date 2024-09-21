// This program calculates how many times the area of a circle of radius r is larger than the area of a circle of radius 1.

#include <stdio.h>

int main() {
  // Declare the radius of the circle.
  int r;

  // Read the radius from the standard input.
  scanf("%d", &r);

  // Calculate the area of a circle of radius r.
  int area_r = r * r;

  // Calculate the area of a circle of radius 1.
  int area_1 = 1 * 1;

  // Calculate the ratio of the areas.
  int ratio = area_r / area_1;

  // Print the ratio to the standard output.
  printf("%d\n", ratio);

  return 0;
}
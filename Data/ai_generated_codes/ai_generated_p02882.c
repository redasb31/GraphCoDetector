#include <stdio.h>
#include <math.h>

int main() {
  // Input: side length of base (a), height (b), volume of water (x)
  int a, b, x;
  scanf("%d %d %d", &a, &b, &x);

  // Calculate the area of the base (a^2)
  int base_area = a * a;

  // Calculate the height of the water level (h)
  double h = (double) x / base_area;

  // Calculate the angle (theta) in radians
  double theta = atan(h / (double) b);

  // Convert the angle to degrees
  double angle = theta * 180 / M_PI;

  // Print the angle in degrees
  printf("%.12lf\n", angle);

  return 0;
}
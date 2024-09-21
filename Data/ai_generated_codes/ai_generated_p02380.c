#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables for side lengths and angle
  int a, b, C;

  // Input the side lengths and angle
  scanf("%d %d %d", &a, &b, &C);

  // Convert the angle from degrees to radians
  double C_rad = C * M_PI / 180;

  // Calculate the area of the triangle
  double S = 0.5 * a * b * sin(C_rad);

  // Calculate the length of the third side using the Law of Cosines
  double c = sqrt(a * a + b * b - 2 * a * b * cos(C_rad));

  // Calculate the length of the circumference
  double L = a + b + c;

  // Calculate the height of the triangle
  double h = b * sin(C_rad);

  // Output the results with precision to 8 decimal places
  printf("%.8lf %.8lf %.8lf\n", S, L, h);

  return 0;
}
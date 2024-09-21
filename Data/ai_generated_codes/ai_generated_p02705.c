#include <stdio.h>
#include <math.h>

int main() {
  // Declare the radius variable
  int R;

  // Get the radius input from the user
  scanf("%d", &R);

  // Calculate the circumference using the formula: 2 * pi * R
  double circumference = 2 * M_PI * R;

  // Print the circumference with appropriate precision
  printf("%.16lf\n", circumference);

  return 0;
}
#include <stdio.h>
#include <math.h>

// Function to calculate the coordinates of a point on a Koch curve
void koch(double x1, double y1, double x2, double y2, int n) {
  // Base case: if n is 0, simply draw a line between the two points
  if (n == 0) {
    printf("%.8lf %.8lf\n", x2, y2);
    return;
  }

  // Calculate the coordinates of the intermediate points
  double x3 = (2 * x1 + x2) / 3;
  double y3 = (2 * y1 + y2) / 3;
  double x4 = (x1 + 2 * x2) / 3;
  double y4 = (y1 + 2 * y2) / 3;
  double x5 = (x3 + x4) / 2 + (y4 - y3) * sqrt(3) / 2;
  double y5 = (y3 + y4) / 2 + (x3 - x4) * sqrt(3) / 2;

  // Recursively draw the Koch curve for the four new segments
  koch(x1, y1, x3, y3, n - 1);
  koch(x3, y3, x5, y5, n - 1);
  koch(x5, y5, x4, y4, n - 1);
  koch(x4, y4, x2, y2, n - 1);
}

int main() {
  int n;

  // Read the depth of the recursion
  scanf("%d", &n);

  // Print the starting point (0, 0)
  printf("0.00000000 0.00000000\n");

  // Draw the Koch curve
  koch(0, 0, 100, 0, n);

  // Print the ending point (100, 0)
  printf("100.00000000 0.00000000\n");

  return 0;
}
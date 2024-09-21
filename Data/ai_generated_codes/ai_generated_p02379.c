#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables to store the coordinates of the two points
  double x1, y1, x2, y2;

  // Read the coordinates from the user
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

  // Calculate the distance using the distance formula
  double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

  // Print the calculated distance
  printf("%.8lf\n", distance);

  return 0;
}
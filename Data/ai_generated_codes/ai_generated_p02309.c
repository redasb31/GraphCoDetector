#include <stdio.h>
#include <math.h>

int main() {
  // Input the coordinates and radii of the two circles
  int c1x, c1y, c1r;
  int c2x, c2y, c2r;
  scanf("%d %d %d", &c1x, &c1y, &c1r);
  scanf("%d %d %d", &c2x, &c2y, &c2r);

  // Calculate the distance between the centers of the circles
  double distance = sqrt(pow(c2x - c1x, 2) + pow(c2y - c1y, 2));

  // Calculate the distance from the center of c1 to the cross point
  double d = (c1r * c1r - c2r * c2r + distance * distance) / (2 * distance);

  // Calculate the coordinates of the cross point relative to the center of c1
  double x = d * (c2x - c1x) / distance;
  double y = d * (c2y - c1y) / distance;

  // Calculate the coordinates of the two cross points
  double x1 = c1x + x;
  double y1 = c1y + y;
  double x2 = c1x - x;
  double y2 = c1y - y;

  // Print the coordinates of the cross points in the required format
  if (x1 < x2) {
    printf("%.8lf %.8lf %.8lf %.8lf\n", x1, y1, x2, y2);
  } else if (x1 == x2 && y1 < y2) {
    printf("%.8lf %.8lf %.8lf %.8lf\n", x1, y1, x2, y2);
  } else {
    printf("%.8lf %.8lf %.8lf %.8lf\n", x2, y2, x1, y1);
  }

  return 0;
}
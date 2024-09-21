#include <stdio.h>
#include <math.h>

int main() {
  // Input the coordinates of the three points
  int x1, y1, x2, y2, x3, y3;
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
  scanf("%d %d", &x3, &y3);

  // Calculate the slopes of the lines connecting the points
  double m1 = (double)(y2 - y1) / (x2 - x1);
  double m2 = (double)(y3 - y2) / (x3 - x2);

  // Calculate the midpoints of the lines connecting the points
  double x12 = (x1 + x2) / 2.0;
  double y12 = (y1 + y2) / 2.0;
  double x23 = (x2 + x3) / 2.0;
  double y23 = (y2 + y3) / 2.0;

  // Calculate the slopes of the perpendicular bisectors
  double m1_perp = -1 / m1;
  double m2_perp = -1 / m2;

  // Calculate the equations of the perpendicular bisectors
  double c1 = y12 - m1_perp * x12;
  double c2 = y23 - m2_perp * x23;

  // Solve for the intersection point (cx, cy) of the perpendicular bisectors
  double cx = (c2 - c1) / (m1_perp - m2_perp);
  double cy = m1_perp * cx + c1;

  // Calculate the distance from the center (cx, cy) to one of the points (radius)
  double r = sqrt((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy));

  // Print the results
  printf("%.12lf %.12lf %.12lf\n", cx, cy, r);

  return 0;
}
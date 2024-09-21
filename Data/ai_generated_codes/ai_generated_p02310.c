#include <stdio.h>
#include <math.h>

int main() {
  // Input the point p and circle c
  int px, py, cx, cy, r;
  scanf("%d %d\n%d %d %d", &px, &py, &cx, &cy, &r);

  // Calculate the distance between p and the center of c
  double dist = sqrt(pow(px - cx, 2) + pow(py - cy, 2));

  // Calculate the slope of the line connecting p and the center of c
  double slope = (double)(py - cy) / (px - cx);

  // Calculate the slope of the tangent lines
  double tangent_slope1 = -1 / slope;
  double tangent_slope2 = -1 / slope;

  // Calculate the y-intercepts of the tangent lines
  double intercept1 = py - tangent_slope1 * px;
  double intercept2 = py - tangent_slope2 * px;

  // Calculate the x-coordinates of the tangent points
  double x1 = (r * r * tangent_slope1 + cx - cy * tangent_slope1) / (tangent_slope1 * tangent_slope1 + 1);
  double x2 = (r * r * tangent_slope2 + cx - cy * tangent_slope2) / (tangent_slope2 * tangent_slope2 + 1);

  // Calculate the y-coordinates of the tangent points
  double y1 = tangent_slope1 * x1 + intercept1;
  double y2 = tangent_slope2 * x2 + intercept2;

  // Print the tangent points in the correct order
  if (x1 < x2 || (x1 == x2 && y1 < y2)) {
    printf("%.10lf %.10lf\n", x1, y1);
    printf("%.10lf %.10lf\n", x2, y2);
  } else {
    printf("%.10lf %.10lf\n", x2, y2);
    printf("%.10lf %.10lf\n", x1, y1);
  }

  return 0;
}
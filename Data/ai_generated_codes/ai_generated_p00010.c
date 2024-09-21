#include <stdio.h>
#include <math.h>

int main() {
  int n, i;
  double x1, y1, x2, y2, x3, y3, p_x, p_y, r;

  // Read the number of datasets
  scanf("%d", &n);

  // Loop through each dataset
  for (i = 0; i < n; i++) {
    // Read the coordinates of the three points
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    // Calculate the center coordinates (p_x, p_y) of the circumscribed circle
    p_x = ((y2 - y1) * (x1 * x1 + y1 * y1) + (y3 - y2) * (x2 * x2 + y2 * y2) + (y1 - y3) * (x3 * x3 + y3 * y3)) / (2 * ((y2 - y1) * x1 + (y3 - y2) * x2 + (y1 - y3) * x3));
    p_y = ((x1 - x2) * (x1 * x1 + y1 * y1) + (x2 - x3) * (x2 * x2 + y2 * y2) + (x3 - x1) * (x3 * x3 + y3 * y3)) / (2 * ((x1 - x2) * y1 + (x2 - x3) * y2 + (x3 - x1) * y3));

    // Calculate the radius (r) of the circumscribed circle
    r = sqrt((x1 - p_x) * (x1 - p_x) + (y1 - p_y) * (y1 - p_y));

    // Print the center coordinates and the radius
    printf("%.3lf %.3lf %.3lf\n", p_x, p_y, r);
  }

  return 0;
}
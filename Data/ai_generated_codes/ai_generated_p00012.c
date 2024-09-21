#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
  return 0.5 * abs((x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1));
}

// Function to determine if a point is inside a triangle
int isPointInTriangle(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp) {
  // Calculate areas of three triangles formed by the point and the triangle's sides
  double area1 = triangleArea(x1, y1, x2, y2, xp, yp);
  double area2 = triangleArea(x2, y2, x3, y3, xp, yp);
  double area3 = triangleArea(x3, y3, x1, y1, xp, yp);

  // The point is inside the triangle if the sum of the three areas equals the area of the triangle
  double totalArea = triangleArea(x1, y1, x2, y2, x3, y3);
  if (fabs(area1 + area2 + area3 - totalArea) < 0.001) {
    return 1; 
  } else {
    return 0;
  }
}

int main() {
  double x1, y1, x2, y2, x3, y3, xp, yp;

  // Read input until EOF
  while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp) != EOF) {
    // Check if the point is inside the triangle
    if (isPointInTriangle(x1, y1, x2, y2, x3, y3, xp, yp)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to calculate the area of a triangle
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
  return 0.5 * abs((x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1));
}

// Function to calculate the inradius of a triangle
double inradius(double x1, double y1, double x2, double y2, double x3, double y3) {
  double s = (distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) + distance(x3, y3, x1, y1)) / 2;
  return triangleArea(x1, y1, x2, y2, x3, y3) / s;
}

// Function to calculate the radii of the Malfatti circles
void malfattiCircles(double x1, double y1, double x2, double y2, double x3, double y3, double *r1, double *r2, double *r3) {
  // Calculate the inradius of the triangle
  double r = inradius(x1, y1, x2, y2, x3, y3);

  // Calculate the radii of the Malfatti circles
  *r1 = (r * (distance(x2, y2, x3, y3) + distance(x1, y1, x3, y3) - distance(x1, y1, x2, y2))) / (distance(x2, y2, x3, y3) + distance(x1, y1, x3, y3) + distance(x1, y1, x2, y2));
  *r2 = (r * (distance(x1, y1, x3, y3) + distance(x1, y1, x2, y2) - distance(x2, y2, x3, y3))) / (distance(x2, y2, x3, y3) + distance(x1, y1, x3, y3) + distance(x1, y1, x2, y2));
  *r3 = (r * (distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) - distance(x1, y1, x3, y3))) / (distance(x2, y2, x3, y3) + distance(x1, y1, x3, y3) + distance(x1, y1, x2, y2));
}

int main() {
  double x1, y1, x2, y2, x3, y3;
  double r1, r2, r3;

  // Read input data
  while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
    // Check for end of input
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0) {
      break;
    }

    // Calculate the radii of the Malfatti circles
    malfattiCircles(x1, y1, x2, y2, x3, y3, &r1, &r2, &r3);

    // Print the output
    printf("%.6lf %.6lf %.6lf\n", r1, r2, r3);
  }

  return 0;
}
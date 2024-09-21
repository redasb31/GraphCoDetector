#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
  return 0.5 * abs((x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1));
}

// Function to calculate the semi-perimeter of a triangle
double semi_perimeter(double a, double b, double c) {
  return (a + b + c) / 2;
}

// Function to calculate the inradius of a triangle
double inradius(double a, double b, double c, double area) {
  return area / semi_perimeter(a, b, c);
}

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the incenter of a triangle
void incenter(double x1, double y1, double x2, double y2, double x3, double y3, double *cx, double *cy) {
  double a = distance(x2, y2, x3, y3);
  double b = distance(x1, y1, x3, y3);
  double c = distance(x1, y1, x2, y2);
  *cx = ((a * x1) + (b * x2) + (c * x3)) / (a + b + c);
  *cy = ((a * y1) + (b * y2) + (c * y3)) / (a + b + c);
}

int main() {
  // Input coordinates of the triangle
  double x1, y1, x2, y2, x3, y3;
  scanf("%lf %lf\n%lf %lf\n%lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

  // Calculate the area of the triangle
  double area = triangle_area(x1, y1, x2, y2, x3, y3);

  // Calculate the lengths of the sides of the triangle
  double a = distance(x2, y2, x3, y3);
  double b = distance(x1, y1, x3, y3);
  double c = distance(x1, y1, x2, y2);

  // Calculate the inradius of the triangle
  double r = inradius(a, b, c, area);

  // Calculate the incenter of the triangle
  double cx, cy;
  incenter(x1, y1, x2, y2, x3, y3, &cx, &cy);

  // Print the coordinates of the incenter and the inradius
  printf("%.16lf %.16lf %.16lf\n", cx, cy, r);

  return 0;
}
#include <stdio.h>
#include <math.h>

// Structure to represent a point in 2D space
typedef struct {
  double x;
  double y;
} Point;

// Function to find the reflection point of p onto the line p1p2
Point reflection(Point p1, Point p2, Point p) {
  // Calculate the slope of the line p1p2
  double slope = (p2.y - p1.y) / (p2.x - p1.x);

  // Calculate the midpoint of the line p1p2
  Point midpoint = { (p1.x + p2.x) / 2, (p1.y + p2.y) / 2 };

  // Calculate the perpendicular slope of the line p1p2
  double perpSlope = -1 / slope;

  // Calculate the equation of the perpendicular line passing through p
  double intercept = p.y - perpSlope * p.x;

  // Find the intersection point of the perpendicular line and the line p1p2
  double x = (intercept - midpoint.y + slope * midpoint.x) / (slope - perpSlope);
  double y = slope * (x - midpoint.x) + midpoint.y;

  // The intersection point is the reflection point
  return (Point){ x, y };
}

int main() {
  // Read input for p1 and p2
  double xp1, yp1, xp2, yp2;
  scanf("%lf %lf %lf %lf", &xp1, &yp1, &xp2, &yp2);

  // Read number of queries
  int q;
  scanf("%d", &q);

  // Loop through each query
  for (int i = 0; i < q; i++) {
    // Read input for point p
    double xp, yp;
    scanf("%lf %lf", &xp, &yp);

    // Create points from input
    Point p1 = { xp1, yp1 };
    Point p2 = { xp2, yp2 };
    Point p = { xp, yp };

    // Find the reflection point
    Point x = reflection(p1, p2, p);

    // Print the reflection point coordinates
    printf("%.10lf %.10lf\n", x.x, x.y);
  }

  return 0;
}
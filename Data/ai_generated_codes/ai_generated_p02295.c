#include <stdio.h>

// Function to calculate the cross product of two vectors
double crossProduct(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}

// Function to find the intersection point of two line segments
void findIntersection(double xp0, double yp0, double xp1, double yp1,
                     double xp2, double yp2, double xp3, double yp3) {
  // Calculate the vectors representing the line segments
  double x1 = xp1 - xp0;
  double y1 = yp1 - yp0;
  double x2 = xp3 - xp2;
  double y2 = yp3 - yp2;

  // Calculate the determinant of the matrix formed by the vectors
  double determinant = crossProduct(x1, y1, x2, y2);

  // If the determinant is zero, the lines are parallel
  if (determinant == 0) {
    printf("Lines are parallel\n");
    return;
  }

  // Calculate the parameters t and u for the intersection point
  double t = crossProduct(xp2 - xp0, yp2 - yp0, x2, y2) / determinant;
  double u = crossProduct(x1, y1, xp2 - xp0, yp2 - yp0) / determinant;

  // Check if the intersection point lies within the line segments
  if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
    // Calculate the coordinates of the intersection point
    double x = xp0 + t * x1;
    double y = yp0 + t * y1;

    // Print the coordinates of the intersection point
    printf("%.10lf %.10lf\n", x, y);
  } else {
    printf("Line segments do not intersect\n");
  }
}

int main() {
  int q;
  scanf("%d", &q);

  // Iterate over the queries
  for (int i = 0; i < q; i++) {
    // Read the coordinates of the end points of the line segments
    double xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xp0, &yp0, &xp1, &yp1,
          &xp2, &yp2, &xp3, &yp3);

    // Find the intersection point
    findIntersection(xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3);
  }

  return 0;
}
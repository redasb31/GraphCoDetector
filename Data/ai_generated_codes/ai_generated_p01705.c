#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points on the x-axis
double distance(double x1, double x2) {
  return fabs(x1 - x2);
}

// Function to calculate the maximum possible side length of a square that can fit within two overlapping circles
double maxSquareSide(double x1, double r1, double x2, double r2) {
  // Calculate the distance between the centers of the circles
  double dist = distance(x1, x2);

  // If the circles do not overlap, return 0
  if (dist > r1 + r2) {
    return 0;
  }

  // Calculate the height of the triangle formed by the centers of the circles and a point where the circles intersect
  double height = sqrt(r1 * r1 - (dist / 2) * (dist / 2));

  // Calculate the side length of the maximum possible square
  double side = 2 * height;

  return side;
}

int main() {
  int N;

  while (scanf("%d", &N) != EOF && N != 0) {
    // Array to store the coordinates and radii of the circles
    double circles[N][2];

    // Read the coordinates and radii of the circles
    for (int i = 0; i < N; i++) {
      scanf("%lf %lf", &circles[i][0], &circles[i][1]);
    }

    // Initialize the maximum side length to 0
    double maxSide = 0;

    // Calculate the maximum side length for each pair of overlapping circles
    for (int i = 0; i < N - 1; i++) {
      double side = maxSquareSide(circles[i][0], circles[i][1], circles[i + 1][0], circles[i + 1][1]);
      if (side > maxSide) {
        maxSide = side;
      }
    }

    // Print the maximum side length
    printf("%.16lf\n", maxSide);
  }

  return 0;
}
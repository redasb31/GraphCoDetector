#include <stdio.h>
#include <math.h>

#define MAX_N 50
#define EPS 1e-6

// Structure to store a point
typedef struct {
  double x;
  double y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the minimum radius of a circle containing all points
double findMinRadius(Point points[], int n) {
  // Initialize the minimum radius to a large value
  double minRadius = 1e9;

  // Iterate over all pairs of points
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // Calculate the distance between the two points
      double dist = distance(points[i], points[j]);

      // Update the minimum radius if the current distance is smaller
      minRadius = fmin(minRadius, dist / 2);
    }
  }

  // Iterate over all points and check if they are within the circle
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // Calculate the distance between the current point and all other points
      double dist = distance(points[i], points[j]);

      // Check if the current point is outside the circle
      if (dist > minRadius + EPS) {
        // Update the minimum radius if the current point is outside
        minRadius = fmax(minRadius, dist / 2);
      }
    }
  }

  return minRadius;
}

int main() {
  int n;
  Point points[MAX_N];

  // Input the number of points
  scanf("%d", &n);

  // Input the coordinates of the points
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }

  // Find the minimum radius
  double minRadius = findMinRadius(points, n);

  // Output the minimum radius
  printf("%.16lf\n", minRadius);

  return 0;
}
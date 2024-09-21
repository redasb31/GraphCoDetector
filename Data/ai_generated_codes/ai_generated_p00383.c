#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point in 2D space
typedef struct {
  int x;
  int y;
} Point;

// Function to calculate the slope of the line passing through two points
double calculateSlope(Point p1, Point p2) {
  if (p2.x - p1.x == 0) {
    return INFINITY;  // Handle vertical lines
  }
  return (double)(p2.y - p1.y) / (p2.x - p1.x);
}

// Function to check if three points are collinear
int areCollinear(Point p1, Point p2, Point p3) {
  // Check if the slope between p1 and p2 is the same as the slope between p1 and p3
  return calculateSlope(p1, p2) == calculateSlope(p1, p3);
}

// Function to check if any combination of K or more points align on a line
int checkAlignment(Point *points, int n, int k) {
  // Iterate through all possible combinations of three points
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int l = j + 1; l < n; l++) {
        // Check if the three points are collinear
        if (areCollinear(points[i], points[j], points[l])) {
          // Check if there are at least K - 3 other points with the same slope
          int count = 3;
          for (int m = 0; m < n; m++) {
            if (m != i && m != j && m != l &&
                areCollinear(points[i], points[j], points[m])) {
              count++;
              if (count >= k) {
                return 1; // Found a combination of K or more points on a line
              }
            }
          }
        }
      }
    }
  }
  return 0; // No combination of K or more points found on a line
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  Point *points = (Point *)malloc(n * sizeof(Point));
  if (points == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // Read the coordinates of the points
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);
  }

  // Check if any combination of K or more points align on a line
  int result = checkAlignment(points, n, k);

  printf("%d\n", result);

  free(points);
  return 0;
}
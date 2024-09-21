#include <stdio.h>
#include <math.h>

// Structure to represent a point
typedef struct {
  int x;
  int y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to check if all points can be placed in the laboratory
int canPlacePoints(int n, Point points[], int h, int w, int r) {
  // Calculate the maximum distance between any two points
  double maxDistance = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      maxDistance = fmax(maxDistance, distance(points[i], points[j]));
    }
  }

  // Check if the maximum distance plus the radius of ICPC is less than or equal to the minimum dimension of the laboratory
  return (maxDistance + 2 * r) <= fmin(h, w);
}

int main() {
  int n, h, w, r;
  scanf("%d %d %d %d", &n, &h, &w, &r);

  // Read the coordinates of the points
  Point points[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);
  }

  // Check if all points can be placed in the laboratory
  if (canPlacePoints(n, points, h, w, r)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
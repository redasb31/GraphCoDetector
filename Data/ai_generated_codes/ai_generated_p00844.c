#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
  double x;
  double y;
} Point;

// Structure to represent a polygon
typedef struct {
  int n;
  Point* points;
} Polygon;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to calculate the minimum width of placement
double minWidth(Polygon polygon1, Polygon polygon2, double L) {
  // Iterate over all possible positions of polygon2 along the x-axis
  double minWidth = INFINITY;
  for (double shift = -500; shift <= 500; shift += 0.1) {
    // Shift polygon2
    for (int i = 0; i < polygon2.n; i++) {
      polygon2.points[i].x += shift;
    }

    // Check if the distance between any point in polygon1 and any point in polygon2
    // is greater than or equal to L
    bool valid = true;
    for (int i = 0; i < polygon1.n; i++) {
      for (int j = 0; j < polygon2.n; j++) {
        if (distance(polygon1.points[i], polygon2.points[j]) < L) {
          valid = false;
          break;
        }
      }
      if (!valid) {
        break;
      }
    }

    // If the placement is valid, update the minimum width
    if (valid) {
      double maxWidth = -INFINITY;
      double minWidth = INFINITY;
      for (int i = 0; i < polygon1.n; i++) {
        maxWidth = fmax(maxWidth, polygon1.points[i].x);
        minWidth = fmin(minWidth, polygon1.points[i].x);
      }
      for (int i = 0; i < polygon2.n; i++) {
        maxWidth = fmax(maxWidth, polygon2.points[i].x);
        minWidth = fmin(minWidth, polygon2.points[i].x);
      }
      minWidth = maxWidth - minWidth;
      if (minWidth < minWidth) {
        minWidth = minWidth;
      }
    }

    // Unshift polygon2
    for (int i = 0; i < polygon2.n; i++) {
      polygon2.points[i].x -= shift;
    }
  }

  return minWidth;
}

// Function to read a polygon from input
Polygon readPolygon() {
  Polygon polygon;
  scanf("%d", &polygon.n);

  // Allocate memory for the points of the polygon
  polygon.points = (Point*)malloc(polygon.n * sizeof(Point));

  // Read the points of the polygon
  for (int i = 0; i < polygon.n; i++) {
    scanf("%lf %lf", &polygon.points[i].x, &polygon.points[i].y);
  }

  return polygon;
}

int main() {
  double L;
  while (scanf("%lf", &L) != EOF && L != 0) {
    // Read the polygons
    Polygon polygon1 = readPolygon();
    Polygon polygon2 = readPolygon();

    // Calculate the minimum width
    double minWidth = minWidth(polygon1, polygon2, L);

    // Print the minimum width
    printf("%.4lf\n", minWidth);

    // Free the memory allocated for the polygons
    free(polygon1.points);
    free(polygon2.points);
  }

  return 0;
}
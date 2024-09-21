#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

int compare_x(const void *a, const void *b) {
  // Compare points based on their x-coordinate.
  Point *pa = (Point *)a;
  Point *pb = (Point *)b;
  return pa->x - pb->x;
}

int compare_y(const void *a, const void *b) {
  // Compare points based on their y-coordinate.
  Point *pa = (Point *)a;
  Point *pb = (Point *)b;
  return pa->y - pb->y;
}

int main() {
  int n;
  scanf("%d", &n);

  // Allocate memory for points.
  Point *points = malloc(n * sizeof(Point));

  // Read the coordinates of each point.
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);
  }

  // Sort the points by x-coordinate.
  qsort(points, n, sizeof(Point), compare_x);

  // Find the maximum Manhattan distance between two points based on their x-coordinates.
  int max_distance_x = abs(points[n - 1].x - points[0].x);

  // Sort the points by y-coordinate.
  qsort(points, n, sizeof(Point), compare_y);

  // Find the maximum Manhattan distance between two points based on their y-coordinates.
  int max_distance_y = abs(points[n - 1].y - points[0].y);

  // Determine the maximum Manhattan distance.
  int max_distance = (max_distance_x > max_distance_y) ? max_distance_x : max_distance_y;

  // Print the result.
  printf("%d\n", max_distance);

  // Free the allocated memory.
  free(points);
  return 0;
}
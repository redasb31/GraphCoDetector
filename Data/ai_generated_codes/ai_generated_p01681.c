#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 8
#define EPS 1e-6

// Structure to represent a point
typedef struct {
  double x, y;
} Point;

// Structure to represent a wall
typedef struct {
  Point start, end;
} Wall;

// Function to calculate the dot product of two vectors
double dot(Point a, Point b) {
  return a.x * b.x + a.y * b.y;
}

// Function to calculate the cross product of two vectors
double cross(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

// Function to calculate the distance between two points
double distance(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to check if a point is inside a segment
int isInsideSegment(Point p, Wall w) {
  double d1 = distance(p, w.start);
  double d2 = distance(p, w.end);
  double d3 = distance(w.start, w.end);
  return fabs(d1 + d2 - d3) < EPS;
}

// Function to find the intersection point of a line and a segment
Point intersection(Point p1, Point p2, Wall w) {
  double t = cross(w.end - w.start, p1 - w.start) / cross(p2 - p1, w.start - w.end);
  return (Point){p1.x + t * (p2.x - p1.x), p1.y + t * (p2.y - p1.y)};
}

// Function to find the reflection point of a point on a wall
Point reflection(Point p, Wall w) {
  Point v = (Point){w.end.x - w.start.x, w.end.y - w.start.y};
  Point n = (Point){-v.y, v.x}; // Normal vector
  double d = dot(p - w.start, n);
  return (Point){p.x + 2 * d * n.x, p.y + 2 * d * n.y};
}

// Function to check if a ball hits a wall
int hitsWall(Point p1, Point p2, Wall w) {
  if (cross(w.end - w.start, p1 - w.start) * cross(w.end - w.start, p2 - w.start) < 0) {
    Point intersectionPoint = intersection(p1, p2, w);
    if (isInsideSegment(intersectionPoint, w)) {
      return 1;
    }
  }
  return 0;
}

// Function to check if a ball hits a wall without hitting its corners
int hitsWallWithoutCorners(Point p1, Point p2, Wall w) {
  if (cross(w.end - w.start, p1 - w.start) * cross(w.end - w.start, p2 - w.start) < 0) {
    Point intersectionPoint = intersection(p1, p2, w);
    if (isInsideSegment(intersectionPoint, w) && distance(intersectionPoint, w.start) > EPS && distance(intersectionPoint, w.end) > EPS) {
      return 1;
    }
  }
  return 0;
}

// Function to find all possible orders of walls
void findOrders(int n, Wall walls[], Point start, int visited[], int currentOrder, int* count) {
  if (currentOrder == n) {
    (*count)++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      // Check if the ball can hit the current wall without hitting corners
      if (hitsWallWithoutCorners(start, walls[i].end, walls[i])) {
        // Mark the current wall as visited
        visited[i] = 1;
        // Find the reflection point
        Point reflectionPoint = reflection(start, walls[i]);
        // Recursively find orders for the remaining walls
        findOrders(n, walls, reflectionPoint, visited, currentOrder + 1, count);
        // Unmark the current wall
        visited[i] = 0;
      }
    }
  }
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    Point start;
    scanf("%lf %lf", &start.x, &start.y);

    Wall walls[MAX_N];
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &walls[i].start.x, &walls[i].start.y);
      if (i == n - 1) {
        walls[i].end = walls[0].start;
      } else {
        walls[i].end = walls[i + 1].start;
      }
    }

    int visited[MAX_N] = {0};
    int count = 0;
    findOrders(n, walls, start, visited, 0, &count);

    printf("%d\n", count);
  }
  return 0;
}
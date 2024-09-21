#include <stdio.h>
#include <math.h>

#define MAX_FLAGS 400

typedef struct {
  int x;
  int y;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to calculate the angle between two vectors
double angle(Point p1, Point p2, Point p3) {
  double a = distance(p2, p1);
  double b = distance(p2, p3);
  double c = distance(p1, p3);
  return acos((a * a + b * b - c * c) / (2 * a * b));
}

// Function to determine the next flag in the spiral order
int nextFlag(Point flags[], int n, Point current, int visited[]) {
  int next = -1;
  double minAngle = 360; // Initialize with a large angle
  double currAngle;

  for (int i = 0; i < n; i++) {
    // Skip visited flags and the current flag
    if (visited[i] || (flags[i].x == current.x && flags[i].y == current.y)) {
      continue;
    }

    // Calculate the angle between the current direction and the flag
    currAngle = angle(current, {0, 0}, flags[i]);

    // Find the flag with the smallest angle to the right
    if (currAngle < minAngle) {
      minAngle = currAngle;
      next = i;
    }

    // Handle cases where multiple flags are on the same straight line
    if (currAngle == minAngle && distance(current, flags[i]) < distance(current, flags[next])) {
      next = i;
    }
  }
  return next;
}

int main() {
  int n;
  Point flags[MAX_FLAGS];
  int visited[MAX_FLAGS];

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    // Input flag positions
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &flags[i].x, &flags[i].y);
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
      visited[i] = 0;
    }

    // Starting point
    Point current = {0, 0};
    visited[0] = 1; // Mark the starting point as visited

    double totalDistance = 0.0;
    int next;

    // Iterate through the flags in spiral order
    while ((next = nextFlag(flags, n, current, visited)) != -1) {
      totalDistance += distance(current, flags[next]);
      current = flags[next];
      visited[next] = 1;
    }

    printf("%.1f\n", totalDistance);
  }

  return 0;
}
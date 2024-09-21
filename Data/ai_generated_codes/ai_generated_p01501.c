#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N 100
#define EPS 1e-9

// Structure for a point
typedef struct {
  double x, y;
} Point;

// Structure for a shelter
typedef struct {
  Point point;
  int id;
} Shelter;

// Function to calculate the distance between two points
double distance(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to check if a point is inside a polygon
int isInsidePolygon(Point point, Point polygon[], int n) {
  int i, j, cross = 0;
  for (i = 0, j = n - 1; i < n; j = i++) {
    if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
        (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) /
                     (polygon[j].y - polygon[i].y) +
             polygon[i].x)) {
      cross++;
    }
  }
  return cross % 2;
}

// Function to find the nearest shelter to a point
Shelter findNearestShelter(Point point, Shelter shelters[], int n) {
  Shelter nearest = shelters[0];
  double minDistance = distance(point, shelters[0].point);
  for (int i = 1; i < n; i++) {
    double dist = distance(point, shelters[i].point);
    if (dist < minDistance) {
      minDistance = dist;
      nearest = shelters[i];
    }
  }
  return nearest;
}

// Function to calculate the expected cost
double calculateExpectedCost(Point town[], int m, Shelter shelters[], int n) {
  double expectedCost = 0;
  // Sample 100000 points inside the polygon
  for (int i = 0; i < 100000; i++) {
    double x = (double)rand() / RAND_MAX * (town[m - 1].x - town[0].x) +
              town[0].x;
    double y = (double)rand() / RAND_MAX * (town[m - 1].y - town[0].y) +
              town[0].y;
    Point point = {x, y};
    if (isInsidePolygon(point, town, m)) {
      Shelter nearest = findNearestShelter(point, shelters, n);
      expectedCost += distance(point, nearest.point) *
                     distance(point, nearest.point);
    }
  }
  return expectedCost / 100000;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);

  Point town[MAX_N];
  Shelter shelters[MAX_N];

  // Read the town coordinates
  for (int i = 0; i < m; i++) {
    scanf("%lf %lf", &town[i].x, &town[i].y);
  }

  // Read the shelter coordinates
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &shelters[i].point.x, &shelters[i].point.y);
    shelters[i].id = i;
  }

  // Calculate the expected cost
  double expectedCost = calculateExpectedCost(town, m, shelters, n);

  // Print the expected cost
  printf("%.10lf\n", expectedCost);

  return 0;
}
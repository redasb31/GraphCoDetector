#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX_POINTS 20

// Structure to represent a point
typedef struct {
  int x;
  int y;
} Point;

// Structure to represent a line segment
typedef struct {
  Point start;
  Point end;
} LineSegment;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the shortest distance between two line segments
double shortestDistance(LineSegment line1, LineSegment line2) {
  double minDistance = INT_MAX;
  // Calculate the distance between all pairs of points from the two line segments
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      double dist = distance(line1.start + i * (line1.end - line1.start),
                            line2.start + j * (line2.end - line2.start));
      minDistance = fmin(minDistance, dist);
    }
  }
  return minDistance;
}

// Function to find the shortest bridge distance
double findShortestBridge(Point westPoints[], int westCount, Point eastPoints[],
                         int eastCount) {
  double minBridge = INT_MAX;
  // Iterate over all pairs of points on the west and east sides
  for (int i = 0; i < westCount; i++) {
    for (int j = 0; j < eastCount; j++) {
      // Calculate the distance between the points
      double dist = distance(westPoints[i], eastPoints[j]);
      minBridge = fmin(minBridge, dist);
    }
  }
  return minBridge;
}

// Function to find the shortest road distance from a point to a line segment
double shortestRoadDistance(Point point, LineSegment line) {
  // Calculate the distance from the point to the start and end points of the line
  double distStart = distance(point, line.start);
  double distEnd = distance(point, line.end);
  // Calculate the distance from the point to the line segment using the formula
  // for the distance from a point to a line
  double distLine =
      fabs((line.end.y - line.start.y) * point.x -
           (line.end.x - line.start.x) * point.y +
           line.end.x * line.start.y - line.end.y * line.start.x) /
      distance(line.start, line.end);
  // Return the minimum of the three distances
  return fmin(fmin(distStart, distEnd), distLine);
}

int main() {
  Point s, t;
  int westCount, eastCount;
  Point westPoints[MAX_POINTS], eastPoints[MAX_POINTS];

  // Read the input
  scanf("%d %d %d %d", &s.x, &s.y, &t.x, &t.y);
  scanf("%d", &westCount);
  for (int i = 0; i < westCount; i++) {
    scanf("%d %d", &westPoints[i].x, &westPoints[i].y);
  }
  scanf("%d", &eastCount);
  for (int i = 0; i < eastCount; i++) {
    scanf("%d %d", &eastPoints[i].x, &eastPoints[i].y);
  }

  // Find the shortest bridge distance
  double bridgeDistance =
      findShortestBridge(westPoints, westCount, eastPoints, eastCount);

  // Find the shortest road distances
  LineSegment westSide = {westPoints[0], westPoints[westCount - 1]};
  LineSegment eastSide = {eastPoints[0], eastPoints[eastCount - 1]};
  double roadDistanceWest = shortestRoadDistance(s, westSide);
  double roadDistanceEast = shortestRoadDistance(t, eastSide);

  // Calculate the total highway length
  double totalHighwayLength = bridgeDistance + roadDistanceWest +
                             roadDistanceEast;

  // Print the output
  printf("%.12lf %.12lf\n", bridgeDistance, totalHighwayLength);

  return 0;
}
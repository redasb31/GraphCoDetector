#include <stdio.h>
#include <math.h>

// Structure to represent a point in 3D space
typedef struct {
  double x;
  double y;
  double z;
} Point;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// Function to calculate the area of a triangle given three points
double triangleArea(Point p1, Point p2, Point p3) {
  double a = distance(p2, p3);
  double b = distance(p1, p3);
  double c = distance(p1, p2);
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to find the minimum area of the shield needed to enclose all points
double minShieldArea(Point points[], int n) {
  double minArea = 0;
  // Calculate the area of each possible triangle formed by three points
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        double area = triangleArea(points[i], points[j], points[k]);
        // Update the minimum area if a larger triangle is found
        if (area > minArea) {
          minArea = area;
        }
      }
    }
  }
  return minArea * 4; // Multiply by 4 to account for all faces of the convex hull
}

int main() {
  int n;
  scanf("%d", &n);

  // Read the coordinates of the points
  Point points[n];
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z);
  }

  // Calculate and print the minimum shield area
  double area = minShieldArea(points, n);
  printf("%.3lf\n", area);

  return 0;
}
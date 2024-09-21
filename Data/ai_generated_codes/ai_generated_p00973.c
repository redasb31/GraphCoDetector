#include <stdio.h>
#include <math.h>

#define MAX_VERTICES 5000

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

// Function to calculate the area of a triangle
double triangleArea(Point a, Point b, Point c) {
  return 0.5 * abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

// Function to calculate the distance between two points
double distance(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the intersection point of two lines
Point intersectionPoint(Point a, Point b, Point c, Point d) {
  double x1 = a.x, y1 = a.y;
  double x2 = b.x, y2 = b.y;
  double x3 = c.x, y3 = c.y;
  double x4 = d.x, y4 = d.y;

  double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  if (denominator == 0) {
    // Lines are parallel or coincident
    return (Point){-1, -1};
  }

  double t = ((x3 - x1) * (y1 - y2) - (y3 - y1) * (x1 - x2)) / denominator;
  double u = ((x3 - x1) * (y3 - y4) - (y3 - y1) * (x3 - x4)) / denominator;

  // Check if the intersection point lies on both line segments
  if (0 <= t && t <= 1 && 0 <= u && u <= 1) {
    return (Point){x1 + t * (x2 - x1), y1 + t * (y2 - y1)};
  } else {
    // Intersection point does not lie on both line segments
    return (Point){-1, -1};
  }
}

// Function to calculate the area of a polygon
double polygonArea(Point polygon[], int n) {
  double area = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
  }
  return 0.5 * abs(area);
}

// Function to find the minimum and maximum lengths of the cut line segments
void findCutLengths(Point polygon[], int n, double *min_length, double *max_length) {
  double totalArea = polygonArea(polygon, n);
  double halfArea = totalArea / 2;

  *min_length = INFINITY;
  *max_length = 0;

  // Iterate over all edges of the polygon
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;

    // Iterate over all vertices of the polygon, excluding the endpoints of the current edge
    for (int k = 0; k < n; k++) {
      if (k != i && k != j) {
        // Calculate the intersection point of the line segment defined by the current edge and the line passing through the current vertex and the midpoint of the current edge
        Point intersection = intersectionPoint(polygon[i], polygon[j], polygon[k], (Point){(polygon[i].x + polygon[j].x) / 2, (polygon[i].y + polygon[j].y) / 2});

        // If an intersection point is found, calculate the distance between the intersection point and the midpoint of the current edge
        if (intersection.x != -1) {
          double length = distance(intersection, (Point){(polygon[i].x + polygon[j].x) / 2, (polygon[i].y + polygon[j].y) / 2});

          // Check if the line segment divides the polygon into two parts of equal area
          double area1 = triangleArea(polygon[i], polygon[j], intersection) + polygonArea(polygon, i + 1) - triangleArea(polygon[i], polygon[j], polygon[k]);
          double area2 = totalArea - area1;

          if (fabs(area1 - halfArea) < 1e-6 || fabs(area2 - halfArea) < 1e-6) {
            // Update minimum and maximum lengths
            *min_length = fmin(*min_length, length);
            *max_length = fmax(*max_length, length);
          }
        }
      }
    }
  }
}

int main() {
  int n;
  Point polygon[MAX_VERTICES];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &polygon[i].x, &polygon[i].y);
  }

  double min_length, max_length;
  findCutLengths(polygon, n, &min_length, &max_length);

  printf("%.12lf\n", min_length);
  printf("%.12lf\n", max_length);

  return 0;
}
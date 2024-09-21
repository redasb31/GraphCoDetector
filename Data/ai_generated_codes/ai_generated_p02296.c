#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to calculate the distance between two segments
double segment_distance(double xp0, double yp0, double xp1, double yp1, double xp2, double yp2, double xp3, double yp3) {
  // Calculate the distance between the closest points of the two segments
  // This is done by finding the distance between the closest points of the two lines containing the segments
  // and then checking if the closest points lie within the segments
  double a = yp1 - yp0;
  double b = xp0 - xp1;
  double c = a * xp0 + b * yp0;
  double d = yp3 - yp2;
  double e = xp2 - xp3;
  double f = d * xp2 + e * yp2;
  double det = a * e - b * d;
  
  // If the lines are parallel, the distance between the segments is the distance between a point on one segment to the other segment
  if (det == 0) {
    return distance(xp0, yp0, xp2, yp2);
  }
  
  // Calculate the coordinates of the closest point on line 1
  double x1 = (e * c - b * f) / det;
  double y1 = (a * f - d * c) / det;
  
  // Calculate the coordinates of the closest point on line 2
  double x2 = (e * c - b * f) / det;
  double y2 = (a * f - d * c) / det;
  
  // Check if the closest points lie within the segments
  if ((x1 >= xp0 && x1 <= xp1 && y1 >= yp0 && y1 <= yp1) && (x2 >= xp2 && x2 <= xp3 && y2 >= yp2 && y2 <= yp3)) {
    return distance(x1, y1, x2, y2);
  }
  
  // If the closest points are not within the segments, then the distance between the segments is the minimum distance between the endpoints of the segments
  else {
    double min_distance = distance(xp0, yp0, xp2, yp2);
    min_distance = fmin(min_distance, distance(xp0, yp0, xp3, yp3));
    min_distance = fmin(min_distance, distance(xp1, yp1, xp2, yp2));
    min_distance = fmin(min_distance, distance(xp1, yp1, xp3, yp3));
    return min_distance;
  }
}

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    double xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xp0, &yp0, &xp1, &yp1, &xp2, &yp2, &xp3, &yp3);
    printf("%.10lf\n", segment_distance(xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3));
  }
  return 0;
}
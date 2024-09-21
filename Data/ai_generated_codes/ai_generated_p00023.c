#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
  int N, i;
  double x_a, y_a, r_a, x_b, y_b, r_b, dist;

  scanf("%d", &N); // Read the number of datasets

  for (i = 0; i < N; i++) {
    scanf("%lf %lf %lf %lf %lf %lf", &x_a, &y_a, &r_a, &x_b, &y_b, &r_b); // Read the coordinates and radii of the circles

    dist = distance(x_a, y_a, x_b, y_b); // Calculate the distance between the centers of the circles

    // Check the intersection conditions
    if (dist < fabs(r_a - r_b)) {
      if (r_a > r_b) {
        printf("2\n"); // Circle B is inside circle A
      } else {
        printf("-2\n"); // Circle A is inside circle B
      }
    } else if (dist < r_a + r_b) {
      printf("1\n"); // Circumference of A and B intersect
    } else {
      printf("0\n"); // A and B do not overlap
    }
  }

  return 0;
}
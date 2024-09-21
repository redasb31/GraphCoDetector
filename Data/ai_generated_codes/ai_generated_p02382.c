#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
  int n; // dimension of the vectors
  scanf("%d", &n);

  int x[n], y[n]; // vectors x and y

  // Read vector x
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }

  // Read vector y
  for (int i = 0; i < n; i++) {
    scanf("%d", &y[i]);
  }

  // Calculate Minkowski's distances for p = 1, 2, 3, and ∞
  double distance_1 = 0.0; // Manhattan distance (p = 1)
  double distance_2 = 0.0; // Euclidean distance (p = 2)
  double distance_3 = 0.0; // p = 3
  double distance_inf = 0.0; // Chebyshev distance (p = ∞)

  for (int i = 0; i < n; i++) {
    double diff = abs(x[i] - y[i]);
    distance_1 += diff;
    distance_2 += diff * diff;
    distance_3 += pow(diff, 3);
    distance_inf = fmax(distance_inf, diff);
  }

  distance_2 = sqrt(distance_2);
  distance_3 = pow(distance_3, 1.0 / 3.0); // Calculate the cube root

  // Print the distances
  printf("%.6lf %.6lf %.6lf %.6lf\n", distance_1, distance_2, distance_3, distance_inf);

  return 0;
}
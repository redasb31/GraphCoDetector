#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
  int N, L;
  int T[3000];

  // Input
  scanf("%d %d", &N, &L);
  for (int i = 0; i < N; i++) {
    scanf("%d", &T[i]);
  }

  // Calculate expected x and y coordinates
  double expected_x = 0.0;
  double expected_y = 0.0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        // Calculate coordinates of the three points
        double x1 = cos(2 * PI * T[i] / L);
        double y1 = sin(2 * PI * T[i] / L);
        double x2 = cos(2 * PI * T[j] / L);
        double y2 = sin(2 * PI * T[j] / L);
        double x3 = cos(2 * PI * T[k] / L);
        double y3 = sin(2 * PI * T[k] / L);

        // Calculate the area of the triangle
        double area = 0.5 * abs((x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1));

        // Calculate the incenter coordinates
        double incenter_x = (x1 + x2 + x3) / 3.0;
        double incenter_y = (y1 + y2 + y3) / 3.0;

        // Update the expected coordinates
        expected_x += incenter_x * area;
        expected_y += incenter_y * area;
      }
    }
  }

  // Normalize the expected coordinates by the total area of all possible triangles
  double total_area = (double)N * (N - 1) * (N - 2) / 6;
  expected_x /= total_area;
  expected_y /= total_area;

  // Output the expected coordinates
  printf("%.15lf %.15lf\n", expected_x, expected_y);

  return 0;
}
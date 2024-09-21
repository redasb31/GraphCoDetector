#include <stdio.h>
#include <math.h>

int main() {
  int n, i, case_number = 1;
  double x[50], y[50], area;

  while (1) {
    scanf("%d", &n);
    if (n == 0) break;

    // Read the coordinates of the vertices
    for (i = 0; i < n; i++) {
      scanf("%lf %lf", &x[i], &y[i]);
    }

    // Calculate the area using the shoelace formula
    area = 0;
    for (i = 0; i < n; i++) {
      area += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
    }
    area = fabs(area) / 2;

    // Print the case number and area
    printf("%d %.1lf\n", case_number++, area);
  }

  return 0;
}
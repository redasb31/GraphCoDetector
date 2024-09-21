#include <stdio.h>

int main() {
  // Number of datasets
  int n;
  scanf("%d", &n);

  // Loop through each dataset
  for (int i = 0; i < n; i++) {
    // Coordinates of points A, B, C, and D
    double x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    // Calculate slopes of lines AB and CD
    double slope_AB = (y2 - y1) / (x2 - x1);
    double slope_CD = (y4 - y3) / (x4 - x3);

    // Check if slopes are equal (parallel lines)
    if (slope_AB == slope_CD) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
  // Input coordinates of p1 and p2
  int xp1, yp1, xp2, yp2;
  scanf("%d %d %d %d", &xp1, &yp1, &xp2, &yp2);

  // Number of queries
  int q;
  scanf("%d", &q);

  // Loop through each query
  for (int i = 0; i < q; i++) {
    // Input coordinates of p
    int xp0, yp0;
    scanf("%d %d", &xp0, &yp0);

    // Calculate the vector p1p2
    int dx12 = xp2 - xp1;
    int dy12 = yp2 - yp1;

    // Calculate the vector p1p
    int dx10 = xp0 - xp1;
    int dy10 = yp0 - yp1;

    // Calculate the dot product of p1p2 and p1p
    int dotProduct = dx12 * dx10 + dy12 * dy10;

    // Calculate the squared magnitude of p1p2
    int magSquared = dx12 * dx12 + dy12 * dy12;

    // Calculate the parameter t for the projection point
    double t = (double)dotProduct / (double)magSquared;

    // Calculate the coordinates of the projection point x
    double xx = xp1 + t * dx12;
    double yy = yp1 + t * dy12;

    // Print the coordinates of the projection point
    printf("%.10lf %.10lf\n", xx, yy);
  }

  return 0;
}
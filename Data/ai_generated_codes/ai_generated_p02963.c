#include <stdio.h>

int main() {
  // S: the given integer
  long long S;
  scanf("%lld", &S);

  // Calculate the base and height of the triangle.
  // We choose base = 2*S and height = 1.
  // This ensures that the area is S/2.
  long long base = 2 * S;
  long long height = 1;

  // Assign coordinates for the vertices of the triangle.
  long long X1 = 0;
  long long Y1 = 0;
  long long X2 = base;
  long long Y2 = 0;
  long long X3 = 0;
  long long Y3 = height;

  // Print the coordinates of the vertices.
  printf("%lld %lld %lld %lld %lld %lld\n", X1, Y1, X2, Y2, X3, Y3);

  return 0;
}
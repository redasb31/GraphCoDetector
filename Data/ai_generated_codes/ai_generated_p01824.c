#include <stdio.h>

int main() {
  // Declare variables
  long long A, B, C, N, x, y, z;
  long long total_surface_area;

  // Read input
  scanf("%lld %lld %lld %lld", &A, &B, &C, &N);

  // Calculate the initial surface area of the rectangular solid
  total_surface_area = 2 * (A * B + A * C + B * C);

  // Iterate through the removed cubes
  for (int i = 0; i < N; i++) {
    // Read the coordinates of the removed cube
    scanf("%lld %lld %lld", &x, &y, &z);

    // Calculate the surface area of the removed cube
    long long cube_surface_area = 6;

    // Adjust the surface area based on the position of the removed cube
    if (x == 0) {
      cube_surface_area -= 2; // Remove the two faces on the x=0 side
    }
    if (x == A - 1) {
      cube_surface_area -= 2; // Remove the two faces on the x=A-1 side
    }
    if (y == 0) {
      cube_surface_area -= 2; // Remove the two faces on the y=0 side
    }
    if (y == B - 1) {
      cube_surface_area -= 2; // Remove the two faces on the y=B-1 side
    }
    if (z == 0) {
      cube_surface_area -= 2; // Remove the two faces on the z=0 side
    }
    if (z == C - 1) {
      cube_surface_area -= 2; // Remove the two faces on the z=C-1 side
    }

    // Subtract the removed surface area from the total surface area
    total_surface_area -= cube_surface_area;
  }

  // Print the result
  printf("%lld\n", total_surface_area);

  return 0;
}
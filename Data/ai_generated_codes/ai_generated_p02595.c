#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables
  int N, D, count = 0;
  int X, Y;

  // Read input
  scanf("%d %d", &N, &D);

  // Iterate over each point
  for (int i = 0; i < N; i++) {
    // Read coordinates of the point
    scanf("%d %d", &X, &Y);

    // Calculate distance from origin
    double distance = sqrt(X * X + Y * Y);

    // Check if distance is within the limit
    if (distance <= D) {
      // Increment count if distance is within limit
      count++;
    }
  }

  // Print the count of points within the limit
  printf("%d\n", count);

  return 0;
}
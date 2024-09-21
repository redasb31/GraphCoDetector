#include <stdio.h>
#include <math.h>

int main() {
  // Read the number of engines
  int N;
  scanf("%d", &N);

  // Read the coordinates of each engine
  int x[N], y[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }

  // Calculate the maximum distance
  double max_distance = 0;
  for (int i = 0; i < (1 << N); i++) {
    // Calculate the coordinates for this combination of engines
    int X = 0, Y = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        X += x[j];
        Y += y[j];
      }
    }
    // Calculate the distance from the origin
    double distance = sqrt(X * X + Y * Y);
    // Update the maximum distance
    max_distance = (distance > max_distance) ? distance : max_distance;
  }

  // Print the maximum distance
  printf("%.10lf\n", max_distance);

  return 0;
}
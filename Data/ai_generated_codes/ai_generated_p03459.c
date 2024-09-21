#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input the number of points
  int N;
  scanf("%d", &N);

  // Allocate memory for the points
  int *t = malloc(N * sizeof(int));
  int *x = malloc(N * sizeof(int));
  int *y = malloc(N * sizeof(int));

  // Input the points and their corresponding times
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &t[i], &x[i], &y[i]);
  }

  // Check if AtCoDeer can reach the first point
  if (t[0] != 1 || abs(x[0]) + abs(y[0]) != 1) {
    printf("No\n");
    free(t);
    free(x);
    free(y);
    return 0;
  }

  // Check if AtCoDeer can reach the remaining points
  for (int i = 1; i < N; i++) {
    // Calculate the maximum distance AtCoDeer can travel in the given time
    int max_distance = t[i] - t[i - 1];

    // Calculate the actual distance AtCoDeer needs to travel
    int distance = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);

    // If the distance to travel is greater than the maximum distance,
    // AtCoDeer cannot reach the point
    if (distance > max_distance) {
      printf("No\n");
      free(t);
      free(x);
      free(y);
      return 0;
    }
  }

  // If AtCoDeer can reach all points, print "Yes"
  printf("Yes\n");

  // Free the allocated memory
  free(t);
  free(x);
  free(y);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input: Number of points
  int N;
  scanf("%d", &N);

  // Input: Time and coordinates of each point
  int *t = (int *)malloc(N * sizeof(int));
  int *x = (int *)malloc(N * sizeof(int));
  int *y = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &t[i], &x[i], &y[i]);
  }

  // Initial position
  int current_x = 0;
  int current_y = 0;
  int current_time = 0;

  // Iterate through each point
  for (int i = 0; i < N; i++) {
    // Time to reach the next point
    int time_to_next = t[i] - current_time;

    // Calculate the maximum distance AtCoDeer can travel in the given time
    int max_distance = time_to_next;

    // Calculate the Manhattan distance to the next point
    int distance = abs(x[i] - current_x) + abs(y[i] - current_y);

    // Check if the distance is achievable
    if (distance > max_distance) {
      printf("No\n");
      free(t);
      free(x);
      free(y);
      return 0;
    }

    // Update current position and time
    current_x = x[i];
    current_y = y[i];
    current_time = t[i];
  }

  // If all points can be visited, print "Yes"
  printf("Yes\n");

  free(t);
  free(x);
  free(y);
  return 0;
}
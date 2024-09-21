#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
  int N, M; // Number of robots and exits
  scanf("%d %d", &N, &M);

  // Allocate memory for robot and exit coordinates
  int *robot_coords = (int *)malloc(N * sizeof(int));
  int *exit_coords = (int *)malloc(M * sizeof(int));

  // Read robot coordinates
  for (int i = 0; i < N; i++) {
    scanf("%d", &robot_coords[i]);
  }

  // Read exit coordinates
  for (int i = 0; i < M; i++) {
    scanf("%d", &exit_coords[i]);
  }

  // Calculate the number of combinations
  long long combinations = 1;
  for (int i = 0; i < N; i++) {
    // Find the nearest exit for each robot
    int nearest_exit = -1;
    int min_distance = INT_MAX;
    for (int j = 0; j < M; j++) {
      int distance = abs(robot_coords[i] - exit_coords[j]);
      if (distance < min_distance) {
        min_distance = distance;
        nearest_exit = j;
      }
    }
    
    // Increment the number of combinations for each nearest exit
    combinations = (combinations * (nearest_exit + 1)) % MOD;
  }

  // Print the result
  printf("%lld\n", combinations);

  // Free allocated memory
  free(robot_coords);
  free(exit_coords);

  return 0;
}
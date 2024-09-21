#include <stdio.h>
#include <stdlib.h>

typedef struct Yokan {
  int left;
  int right;
} Yokan;

// Compare function for qsort to sort yokans by their left endpoint
int compare_yokans(const void *a, const void *b) {
  Yokan *yo1 = (Yokan *)a;
  Yokan *yo2 = (Yokan *)b;
  return yo1->left - yo2->left;
}

int main() {
  int N, M; // Number of yokans and shuttle run distance
  scanf("%d %d", &N, &M);

  // Allocate memory for yokans
  Yokan *yokans = malloc(N * sizeof(Yokan));
  if (yokans == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    return 1;
  }

  // Read the yokan positions
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &yokans[i].left, &yokans[i].right);
  }

  // Sort yokans by their left endpoints
  qsort(yokans, N, sizeof(Yokan), compare_yokans);

  // Initialize variables
  int current_position = 0; // Homura-chan's current position
  int distance = 0; // Total distance traveled
  int direction = 1; // Direction of movement (1: positive, -1: negative)

  // Iterate through the yokans
  for (int i = 0; i < N; i++) {
    // If Homura-chan is already in the range of the yokan, skip
    if (current_position >= yokans[i].left && current_position <= yokans[i].right) {
      continue;
    }

    // Calculate distance to reach the start of the yokan
    int distance_to_yokan = abs(yokans[i].left - current_position);

    // If Homura-chan needs to change direction
    if (direction * (yokans[i].left - current_position) < 0) {
      // Calculate the distance to reach the end of the shuttle run
      distance += M - current_position; 
      // Change direction and update current position
      direction *= -1;
      current_position = M;
      // Calculate the distance to reach the start of the yokan
      distance_to_yokan = abs(yokans[i].left - current_position);
    }

    // Add the distance to reach the yokan
    distance += distance_to_yokan;

    // Eat the yokan
    current_position = yokans[i].right;
  }

  // Print the minimum distance
  printf("%d\n", distance);

  // Free allocated memory
  free(yokans);

  return 0;
}
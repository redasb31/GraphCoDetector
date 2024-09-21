#include <stdio.h>
#include <stdlib.h>

// Structure to represent a lamp
typedef struct {
  long long x;
  long long y;
} Lamp;

// Function to compare two lamps based on their x-coordinate
int compare_lamps(const void *a, const void *b) {
  Lamp *lamp_a = (Lamp *)a;
  Lamp *lamp_b = (Lamp *)b;
  return lamp_a->x - lamp_b->x;
}

int main() {
  // Read the number of lamps
  int N;
  scanf("%d", &N);

  // Allocate memory for lamps
  Lamp *lamps = malloc(N * sizeof(Lamp));
  if (lamps == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    return 1;
  }

  // Read the coordinates of each lamp
  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &lamps[i].x, &lamps[i].y);
  }

  // Sort lamps by x-coordinate
  qsort(lamps, N, sizeof(Lamp), compare_lamps);

  // Initialize the X-coordinate to the x-coordinate of the first lamp
  long long X = lamps[0].x;

  // Iterate over the lamps and adjust the X-coordinate if necessary
  for (int i = 1; i < N; i++) {
    // Check if the current lamp has a y-coordinate that is greater than
    // the y-coordinate of the previous lamp
    if (lamps[i].y > lamps[i - 1].y) {
      // If so, the X-coordinate needs to be shifted to the left
      X = lamps[i].x - (lamps[i].y - lamps[i - 1].y);
    }
  }

  // Print the X-coordinate
  printf("%lld\n", X);

  // Free allocated memory
  free(lamps);

  return 0;
}
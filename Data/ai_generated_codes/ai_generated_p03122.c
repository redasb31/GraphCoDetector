#include <stdio.h>
#include <stdlib.h>

// Structure to store the coordinates of a lamp
typedef struct {
  long long x;
  long long y;
} Lamp;

// Function to compare two lamps based on their x-coordinate (for sorting)
int compare_lamps(const void *a, const void *b) {
  Lamp *lamp_a = (Lamp *)a;
  Lamp *lamp_b = (Lamp *)b;
  return lamp_a->x - lamp_b->x;
}

// Function to find the initial lamp position (X, Y)
void find_initial_lamp(Lamp *lamps, int n, long long *X, long long *Y) {
  // Sort the lamps based on their x-coordinate
  qsort(lamps, n, sizeof(Lamp), compare_lamps);

  // Find the lamp with the smallest x-coordinate
  Lamp *min_x_lamp = &lamps[0];

  // Find the lamp with the largest x-coordinate
  Lamp *max_x_lamp = &lamps[n - 1];

  // If the y-coordinates of the smallest and largest x-coordinate lamps are
  // consecutive, then the initial lamp is at the intersection of the line
  // connecting these two lamps and the x-axis
  if (max_x_lamp->y == min_x_lamp->y + 1) {
    *X = min_x_lamp->x;
    *Y = min_x_lamp->y;
  } else {
    // If the y-coordinates are not consecutive, then the initial lamp is
    // located on the line connecting the smallest x-coordinate lamp and the
    // lamp with the second smallest x-coordinate.
    // We find the intersection of this line with the x-axis to get X and Y.
    Lamp *second_min_x_lamp = &lamps[1];
    *X = second_min_x_lamp->x - (second_min_x_lamp->y - min_x_lamp->y);
    *Y = 0;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  Lamp lamps[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &lamps[i].x, &lamps[i].y);
  }

  long long X, Y;
  find_initial_lamp(lamps, n, &X, &Y);

  printf("%lld %lld\n", X, Y);

  return 0;
}
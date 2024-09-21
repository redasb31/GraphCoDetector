#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: number of places
  int N;
  // T: average temperature at sea level
  int T;
  // A: desired temperature
  int A;
  // H_i: elevation of place i
  int *H;
  // index of the place with the closest temperature
  int closest_index = 0;
  // difference between desired temperature and actual temperature
  int difference = abs(A - (T - H[0] * 0.006));

  // Read input
  scanf("%d", &N);
  scanf("%d %d", &T, &A);

  // Allocate memory for elevations
  H = (int *)malloc(N * sizeof(int));

  // Read elevations
  for (int i = 0; i < N; i++) {
    scanf("%d", &H[i]);
  }

  // Find the place with the closest temperature
  for (int i = 1; i < N; i++) {
    int current_difference = abs(A - (T - H[i] * 0.006));
    if (current_difference < difference) {
      closest_index = i;
      difference = current_difference;
    }
  }

  // Print the index of the place
  printf("%d\n", closest_index + 1);

  // Free allocated memory
  free(H);

  return 0;
}
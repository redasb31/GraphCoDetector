#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: number of participants (excluding Takahashi)
  int N;
  scanf("%d", &N);

  // D: array to store time differences
  int *D = (int *)malloc((N + 1) * sizeof(int));

  // Read time differences for each participant
  for (int i = 0; i <= N; i++) {
    scanf("%d", &D[i]);
  }

  // Calculate the maximum possible time gap (s)
  int s = 12; // Initialize with the maximum possible value

  // Iterate over all pairs of participants to find the smallest time gap
  for (int i = 0; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      // Calculate the time difference between participant i and j
      int diff = abs(D[i] - D[j]);

      // Choose the smaller of diff and 24-diff
      diff = (diff < (24 - diff)) ? diff : (24 - diff);

      // Update the minimum time gap (s)
      s = (s < diff) ? s : diff;
    }
  }

  // Print the maximum possible time gap
  printf("%d\n", s);

  // Free dynamically allocated memory
  free(D);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum time to light K candles
int findMinTime(int N, int K, int *x) {
  // If K is 0, no candles need to be lit
  if (K == 0) {
    return 0;
  }

  // Sort the positions of the candles in ascending order
  qsort(x, N, sizeof(int), compare);

  // Calculate the total time required
  int totalTime = 0;
  int currentPosition = 0;
  int i = 0;
  for (i = 0; i < K; i++) {
    // Move to the position of the next candle
    totalTime += abs(x[i] - currentPosition);
    currentPosition = x[i];
  }

  // Return the minimum time
  return totalTime;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  // Read the input
  int N, K;
  scanf("%d %d", &N, &K);
  int *x = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }

  // Find the minimum time
  int minTime = findMinTime(N, K, x);

  // Print the output
  printf("%d\n", minTime);

  // Free the allocated memory
  free(x);

  return 0;
}
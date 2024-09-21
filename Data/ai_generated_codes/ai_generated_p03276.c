#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  // Function to compare two integers for qsort.
  return (*(int *)a - *(int *)b);
}

int main() {
  int N, K; // Number of candles and number of candles to light.
  scanf("%d %d", &N, &K);

  int *x = malloc(N * sizeof(int)); // Array to store the positions of the candles.

  // Input the positions of the candles.
  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
  }

  // Sort the candle positions in ascending order.
  qsort(x, N, sizeof(int), compare);

  // Calculate the minimum time required.
  int time = 0;
  for (int i = 0; i < K; i++) {
    // Calculate the distance to the next candle and update the time.
    time += abs(x[i]) + abs(x[i] - x[i - 1]);
  }

  // Print the minimum time.
  printf("%d\n", time);

  free(x); // Free the allocated memory.
  return 0;
}
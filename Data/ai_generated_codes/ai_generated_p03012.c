#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: number of weights
  int N;
  // W: array to store the weights
  int *W;
  // min_diff: minimum absolute difference between the sums of the two groups
  int min_diff = 10000; // Initialize with a large value

  // Read the number of weights
  scanf("%d", &N);

  // Allocate memory for the weights array
  W = (int *)malloc(N * sizeof(int));

  // Read the weights
  for (int i = 0; i < N; i++) {
    scanf("%d", &W[i]);
  }

  // Calculate the minimum absolute difference
  for (int T = 1; T < N; T++) {
    // Calculate the sum of the weights in the first group
    int S1 = 0;
    for (int i = 0; i < T; i++) {
      S1 += W[i];
    }

    // Calculate the sum of the weights in the second group
    int S2 = 0;
    for (int i = T; i < N; i++) {
      S2 += W[i];
    }

    // Calculate the absolute difference between the sums
    int diff = abs(S1 - S2);

    // Update the minimum absolute difference
    if (diff < min_diff) {
      min_diff = diff;
    }
  }

  // Print the minimum absolute difference
  printf("%d\n", min_diff);

  // Free the allocated memory
  free(W);

  return 0;
}
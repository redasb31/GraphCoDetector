#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input variables
  int N, M, K, Q;
  int *O; // Array of open numbers
  int *X; // Array of sums for each round

  // Read input
  scanf("%d %d %d %d", &N, &M, &K, &Q);

  O = malloc(N * sizeof(int));
  X = malloc(Q * sizeof(int));

  // Read open numbers
  for (int i = 0; i < N; i++) {
    scanf("%d", &O[i]);
  }

  // Read sums for each round
  for (int i = 0; i < Q; i++) {
    scanf("%d", &X[i]);
  }

  // For each round
  for (int i = 0; i < Q; i++) {
    // Initialize an array to track the open numbers needed for the sum
    int *used = calloc(N, sizeof(int));
    int sum = 0;

    // Calculate the sum of the open numbers needed to reach the target sum
    for (int j = 0; j < N; j++) {
      if (sum + O[j] <= X[i]) {
        sum += O[j];
        used[j] = 1;
      } else {
        break;
      }
    }

    // Check if the sum is equal to the target sum
    if (sum == X[i]) {
      // If the sum is equal, print the indices of the open numbers used
      for (int j = 0; j < N; j++) {
        if (used[j] == 1) {
          printf("%d ", j + 1);
        }
      }
    } else {
      // If the sum is not equal, print -1
      printf("-1");
    }

    // Print a newline after each round
    printf("\n");

    // Free memory allocated for used array
    free(used);
  }

  // Free memory allocated for O and X arrays
  free(O);
  free(X);

  return 0;
}
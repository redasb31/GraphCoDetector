#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read the input values
  int N, A, B;
  scanf("%d %d %d", &N, &A, &B);

  // Check if the constraints are met
  if (N < 1 || N > 3 * 100000 || A < 1 || A > 3 * 100000 || B < 1 || B > 3 * 100000) {
    printf("-1\n");
    return 0;
  }

  // If A and B are equal, we need to check if N is also equal
  if (A == B) {
    if (N == A) {
      // Create a sequence with increasing order if A and B are equal
      for (int i = 1; i <= N; i++) {
        printf("%d ", i);
      }
      printf("\n");
    } else {
      printf("-1\n");
    }
    return 0;
  }

  // If A is greater than B, we construct the sequence by building
  // increasing subsequences of size B, and then add the rest of the numbers
  // in decreasing order.
  if (A > B) {
    // Create the sequence
    int* sequence = (int*)malloc(N * sizeof(int));
    int i = 0;

    // Build increasing subsequences of size B
    for (int j = 0; j < A - B; j++) {
      for (int k = 0; k < B; k++) {
        sequence[i++] = B * j + k + 1;
      }
    }

    // Add the remaining numbers in decreasing order
    for (int k = A - 1; k >= B; k--) {
      sequence[i++] = k + 1;
    }

    // Print the sequence
    for (int j = 0; j < N; j++) {
      printf("%d ", sequence[j]);
    }
    printf("\n");

    free(sequence);
  } else {
    // If B is greater than A, we construct the sequence by building
    // decreasing subsequences of size A, and then add the rest of the numbers
    // in increasing order.
    int* sequence = (int*)malloc(N * sizeof(int));
    int i = 0;

    // Build decreasing subsequences of size A
    for (int j = 0; j < B - A; j++) {
      for (int k = 0; k < A; k++) {
        sequence[i++] = (A - k) + A * j;
      }
    }

    // Add the remaining numbers in increasing order
    for (int k = B; k <= N; k++) {
      sequence[i++] = k;
    }

    // Print the sequence
    for (int j = 0; j < N; j++) {
      printf("%d ", sequence[j]);
    }
    printf("\n");

    free(sequence);
  }
  return 0;
}
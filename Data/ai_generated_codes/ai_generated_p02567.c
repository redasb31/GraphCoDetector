#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

int main() {
  // Input variables
  int N, Q;
  int *A = (int *)malloc(sizeof(int) * MAX_N); // Array A
  int T, X, V, L, R;

  // Input N and Q
  scanf("%d %d", &N, &Q);

  // Input array A
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Process each query
  for (int i = 0; i < Q; i++) {
    // Read query type
    scanf("%d", &T);

    // Handle query type 1: Replace value
    if (T == 1) {
      scanf("%d %d", &X, &V);
      A[X - 1] = V; // Adjust index to 0-based
    }
    // Handle query type 2: Find maximum
    else if (T == 2) {
      scanf("%d %d", &L, &R);
      int max_value = A[L - 1]; // Adjust indices to 0-based
      for (int j = L; j <= R; j++) {
        if (A[j - 1] > max_value) {
          max_value = A[j - 1];
        }
      }
      printf("%d\n", max_value);
    }
    // Handle query type 3: Find minimum index
    else if (T == 3) {
      scanf("%d %d", &X, &V);
      int j;
      for (j = X - 1; j < N; j++) { // Adjust index to 0-based
        if (A[j] >= V) {
          break;
        }
      }
      printf("%d\n", j + 1); // Print j+1 as it is 1-based
    }
  }

  free(A); // Free dynamically allocated memory
  return 0;
}
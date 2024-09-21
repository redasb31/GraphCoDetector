#include <stdio.h>
#include <stdlib.h>

int main() {
  // Get the length of the sequence
  int N;
  scanf("%d", &N);

  // Allocate memory for the sequence
  int *a = (int *)malloc(sizeof(int) * N);

  // Read the sequence of digits
  for (int i = 0; i < N; i++) {
    scanf("%1d", &a[i]);
  }

  // Initialize the first row of x
  int *x = (int *)malloc(sizeof(int) * (N + 1)); // Allocate for N+1 elements
  for (int i = 0; i < N; i++) {
    x[i + 1] = a[i]; // Use index i+1 to align with the problem statement
  }

  // Calculate x_i,j for all i and j
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= N + 1 - i; j++) {
      x[j] = abs(x[j] - x[j + 1]);
    }
  }

  // Print the result
  printf("%d\n", x[1]);

  // Free allocated memory
  free(a);
  free(x);

  return 0;
}
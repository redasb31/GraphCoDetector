#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  scanf("%d", &N);

  // Allocate memory for sequences A and B
  int *A = (int *)malloc(sizeof(int) * N);
  int *B = (int *)malloc(sizeof(int) * N);

  // Read input sequences
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }

  // Calculate the number of candies
  int candies = 0;
  for (int i = 0; i < N; i++) {
    // Find the difference between elements
    int diff = abs(A[i] - B[i]);
    // Increment the number of candies by the difference
    candies += diff;
  }

  // Print the result
  printf("%d\n", candies);

  // Free allocated memory
  free(A);
  free(B);

  return 0;
}
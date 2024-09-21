#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  int N; // Number of integers
  scanf("%d", &N);

  // Allocate memory for the array of integers
  int *A = (int *)malloc(N * sizeof(int));

  // Read the integers from input
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Sort the array in ascending order
  qsort(A, N, sizeof(int), compare);

  // Calculate the maximum sum of absolute differences
  long long max_sum = 0;
  for (int i = 1; i < N; i++) {
    max_sum += abs(A[i] - A[i - 1]);
  }

  // Print the maximum sum
  printf("%lld\n", max_sum);

  // Free allocated memory
  free(A);

  return 0;
}
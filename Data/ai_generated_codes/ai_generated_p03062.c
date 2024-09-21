#include <stdio.h>
#include <stdlib.h>

int main() {
  // Get the number of integers
  int N;
  scanf("%d", &N);

  // Allocate memory for the array of integers
  int *A = (int *)malloc(sizeof(int) * N);

  // Read the integers into the array
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the maximum possible sum
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    // If the current integer is negative, multiply it by -1 and add to the sum
    if (A[i] < 0) {
      A[i] *= -1;
      sum += A[i];
    } else {
      // Otherwise, simply add the integer to the sum
      sum += A[i];
    }
  }

  // Print the maximum possible sum
  printf("%lld\n", sum);

  // Free the allocated memory
  free(A);

  return 0;
}
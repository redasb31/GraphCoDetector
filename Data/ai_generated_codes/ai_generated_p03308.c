#include <stdio.h>

int main() {
  // Declare variables for the number of elements (N) and the array (A).
  int N;
  int A[100];

  // Read the number of elements (N).
  scanf("%d", &N);

  // Read the elements of the array (A).
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize the maximum absolute difference to 0.
  int max_diff = 0;

  // Find the maximum and minimum values in the array.
  int max_val = A[0];
  int min_val = A[0];
  for (int i = 1; i < N; i++) {
    if (A[i] > max_val) {
      max_val = A[i];
    }
    if (A[i] < min_val) {
      min_val = A[i];
    }
  }

  // Calculate the maximum absolute difference.
  max_diff = max_val - min_val;

  // Print the maximum absolute difference.
  printf("%d\n", max_diff);

  return 0;
}
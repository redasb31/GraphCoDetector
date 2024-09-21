#include <stdio.h>

int main() {
  // Get the length of the sequence
  int N;
  scanf("%d", &N);

  // Declare an array to store the sequence
  int A[N];

  // Read the sequence from input
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Find the maximum value in the sequence
  int max_value = A[0];
  for (int i = 1; i < N; i++) {
    if (A[i] > max_value) {
      max_value = A[i];
    }
  }

  // Print the maximum value for each element
  for (int i = 0; i < N; i++) {
    // Find the maximum value excluding the current element
    int current_max = 0;
    for (int j = 0; j < N; j++) {
      if (i != j && A[j] > current_max) {
        current_max = A[j];
      }
    }

    // Print the maximum value
    printf("%d\n", current_max);
  }

  return 0;
}
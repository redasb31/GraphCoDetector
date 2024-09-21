#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of operations required to make all elements equal
int minOperations(int N, int K, int *A) {
  // Initialize the number of operations to 0
  int operations = 0;

  // Iterate over the sequence, starting from the first element
  for (int i = 0; i < N; i++) {
    // If the current element is not equal to the minimum value in the subsequence of length K starting from the current element,
    // then we need to perform an operation
    if (A[i] != A[i + K - 1]) {
      // Update the number of operations
      operations++;
      // Find the minimum value in the subsequence of length K starting from the current element
      int minVal = A[i];
      for (int j = i + 1; j < i + K; j++) {
        if (A[j] < minVal) {
          minVal = A[j];
        }
      }
      // Replace all elements in the subsequence with the minimum value
      for (int j = i; j < i + K; j++) {
        A[j] = minVal;
      }
    }
  }

  // Return the number of operations
  return operations;
}

int main() {
  // Read the input values for N and K
  int N, K;
  scanf("%d %d", &N, &K);

  // Allocate memory for the array A
  int *A = (int *)malloc(N * sizeof(int));

  // Read the input values for the array A
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the minimum number of operations
  int operations = minOperations(N, K, A);

  // Print the result
  printf("%d\n", operations);

  // Free the allocated memory
  free(A);

  return 0;
}
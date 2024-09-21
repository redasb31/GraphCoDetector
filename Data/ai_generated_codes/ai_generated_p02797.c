#include <stdio.h>

int main() {
  // Input variables
  int N, K, S;

  // Read input from standard input
  scanf("%d %d %d", &N, &K, &S);

  // Create an array to store the sequence
  int A[N];

  // Calculate the initial value for the sequence
  int initialValue = S / K;

  // Fill the array with the initial value
  for (int i = 0; i < N; i++) {
    A[i] = initialValue;
  }

  // Adjust the sequence to match the number of pairs
  int count = 0;
  int i = 0;
  while (count < K) {
    // Increase the value at the current index
    A[i]++;
    // Increase the count if the current index is within the range of the pair
    if (i + 1 < N) {
      count++;
    }
    // Move to the next index
    i++;
    // Wrap around the array if necessary
    if (i == N) {
      i = 0;
    }
  }

  // Print the sequence
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }

  // Add a newline at the end of the output
  printf("\n");

  return 0;
}
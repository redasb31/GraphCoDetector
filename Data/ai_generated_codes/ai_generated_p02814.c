#include <stdio.h>

int main() {
  // N: Number of even numbers in the sequence
  // M: Upper limit for checking semi-common multiples
  int N, M;
  scanf("%d %d", &N, &M);

  // Array to store the even numbers in the sequence
  int A[100000];

  // Read the sequence of even numbers
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Count the number of semi-common multiples
  int count = 0;

  // Iterate through all numbers from 1 to M
  for (int X = 1; X <= M; X++) {
    // Flag to check if X is a semi-common multiple
    int is_semi_common = 1;

    // Iterate through the sequence of even numbers
    for (int i = 0; i < N; i++) {
      // Check if X is divisible by a_i and leaves a remainder of a_i/2
      if ((X % A[i] != 0) || (X % A[i] != A[i] / 2)) {
        // If not, X is not a semi-common multiple
        is_semi_common = 0;
        break;
      }
    }

    // If X is a semi-common multiple, increment the count
    if (is_semi_common) {
      count++;
    }
  }

  // Print the count of semi-common multiples
  printf("%d\n", count);

  return 0;
}
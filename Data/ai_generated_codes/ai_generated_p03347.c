#include <stdio.h>

int main() {
  int N; // Length of the sequence
  scanf("%d", &N);

  // Array to store the target sequence
  int A[200005];

  // Read the target sequence
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  // Check if the sequence can be generated
  int operations = 0; // Count of operations
  for (int i = N; i > 1; i--) {
    // If the current element is less than the previous element, it cannot be generated
    if (A[i] < A[i - 1]) {
      printf("-1\n");
      return 0;
    }
    // Calculate the number of operations required for the current element
    operations += A[i] - A[i - 1];
  }

  // Print the minimum number of operations
  printf("%d\n", operations);

  return 0;
}
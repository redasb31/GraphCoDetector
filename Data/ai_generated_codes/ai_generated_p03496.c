#include <stdio.h>

int main() {
  int N, i, j;
  int a[51]; // Array to store the sequence
  int operations = 0; // Counter for the number of operations

  // Input the number of elements in the sequence
  scanf("%d", &N);

  // Input the sequence
  for (i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
  }

  // Perform operations to make the sequence non-decreasing
  for (i = 1; i < N; i++) {
    // If the current element is less than the next element, no operation is needed
    if (a[i] <= a[i + 1]) {
      continue;
    }

    // If the current element is greater than the next element, add the current element to the next element
    a[i + 1] += a[i];
    operations++;

    // Output the operation
    printf("%d %d\n", i, i + 1);
  }

  // Output the total number of operations
  printf("%d\n", operations);

  return 0;
}
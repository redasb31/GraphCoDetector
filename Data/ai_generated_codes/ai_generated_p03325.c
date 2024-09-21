#include <stdio.h>

int main() {
  // N: the length of the sequence
  int N;
  // a: the sequence
  int a[10000];
  // operations: the number of operations that can be performed
  int operations = 0;

  // Read the input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Count the number of operations
  for (int i = 0; i < N; i++) {
    // While the current element is even, divide it by 2 and increment the number of operations
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      operations++;
    }
  }

  // Print the result
  printf("%d\n", operations);

  return 0;
}
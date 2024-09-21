// This program finds the N-th smallest integer that is divisible by 100 exactly D times.

#include <stdio.h>

int main() {
  // Declare variables to store the input values.
  int D, N;

  // Read the input values from the user.
  scanf("%d %d", &D, &N);

  // Calculate the N-th smallest integer that is divisible by 100 exactly D times.
  int result = N + (D * 100);

  // Print the result.
  printf("%d\n", result);

  return 0;
}
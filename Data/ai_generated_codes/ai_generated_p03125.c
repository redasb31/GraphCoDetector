#include <stdio.h>

int main() {
  // Declare variables for input values
  int A, B;

  // Read input values from standard input
  scanf("%d %d", &A, &B);

  // Check if A is a divisor of B
  if (B % A == 0) {
    // If A is a divisor of B, print their sum
    printf("%d\n", A + B);
  } else {
    // Otherwise, print the difference between B and A
    printf("%d\n", B - A);
  }

  return 0;
}
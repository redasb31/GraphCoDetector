#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int X, A;

  // Read the input values from the user
  scanf("%d %d", &X, &A);

  // Check if X is less than A
  if (X < A) {
    // If X is less than A, print 0
    printf("0\n");
  } else {
    // If X is not less than A, print 10
    printf("10\n");
  }

  return 0;
}
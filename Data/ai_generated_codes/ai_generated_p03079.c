#include <stdio.h>

int main() {
  // Declare variables to store the side lengths of the triangle.
  int A, B, C;

  // Read the side lengths from the user.
  scanf("%d %d %d", &A, &B, &C);

  // Check if all three sides are equal.
  if (A == B && B == C) {
    // If all three sides are equal, then it is an equilateral triangle.
    printf("Yes\n");
  } else {
    // Otherwise, it is not an equilateral triangle.
    printf("No\n");
  }

  return 0;
}
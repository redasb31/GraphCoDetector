#include <stdio.h>

int main() {
  // Declare variables for the window width and curtain length
  int A, B;

  // Read the window width and curtain length from the user
  scanf("%d %d", &A, &B);

  // Calculate the total covered length by the curtains
  int coveredLength = B * 2;

  // Calculate the uncovered length 
  int uncoveredLength = A - coveredLength;

  // If the curtains cover the entire window, the uncovered length is 0
  if (uncoveredLength < 0) {
    uncoveredLength = 0;
  }

  // Print the uncovered length
  printf("%d\n", uncoveredLength);

  return 0;
}
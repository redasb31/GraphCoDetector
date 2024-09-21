#include <stdio.h>

int main() {
  int A, B; // Declare variables for the two input integers

  // Read the input values for A and B
  scanf("%d %d", &A, &B); 

  // Check if both A and B are within the range of 1 to 9
  if (A >= 1 && A <= 9 && B >= 1 && B <= 9) {
    // If both A and B are within range, print the product
    printf("%d\n", A * B);
  } else {
    // Otherwise, print -1
    printf("-1\n");
  }

  return 0;
}
#include <stdio.h>

int main() {
  // Declare variables for the three integers
  int A1, A2, A3;

  // Read the three integers from standard input
  scanf("%d %d %d", &A1, &A2, &A3);

  // Calculate the sum of the three integers
  int sum = A1 + A2 + A3;

  // Check if the sum is greater than or equal to 22
  if (sum >= 22) {
    // If the sum is greater than or equal to 22, print "bust"
    printf("bust\n");
  } else {
    // If the sum is less than 22, print "win"
    printf("win\n");
  }

  return 0;
}
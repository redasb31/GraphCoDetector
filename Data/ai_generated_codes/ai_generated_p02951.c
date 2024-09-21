#include <stdio.h>

int main() {
  // Declare variables for bottle capacities and water amounts
  int A, B, C;

  // Read input values from the user
  scanf("%d %d %d", &A, &B, &C);

  // Calculate the amount of water that can be transferred
  int transfer = A - B;

  // If the amount of water in Bottle 2 is less than the transferable amount, transfer all water
  if (C < transfer) {
    transfer = C;
  }

  // Calculate the remaining water in Bottle 2
  int remainingWater = C - transfer;

  // Print the remaining water in Bottle 2
  printf("%d\n", remainingWater);

  return 0;
}
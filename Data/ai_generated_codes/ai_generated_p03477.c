#include <stdio.h>

int main() {
  // Declare variables to store the weights of the masses
  int A, B, C, D;

  // Read the weights of the masses from the standard input
  scanf("%d %d %d %d", &A, &B, &C, &D);

  // Calculate the total weight on the left pan
  int leftWeight = A + B;

  // Calculate the total weight on the right pan
  int rightWeight = C + D;

  // Compare the weights on the left and right pans and print the result
  if (leftWeight > rightWeight) {
    printf("Left\n");
  } else if (leftWeight == rightWeight) {
    printf("Balanced\n");
  } else {
    printf("Right\n");
  }

  return 0;
}
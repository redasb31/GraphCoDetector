#include <stdio.h>

int main() {
  // Declare variables to store the number of pieces each person wants to eat
  int A, B;

  // Read the input values from the user
  scanf("%d %d", &A, &B);

  // Check if the total number of pieces requested exceeds the total number of pieces
  if (A + B > 16) {
    printf(":( \n");
    return 0;
  }

  // Check if the requested pieces can be taken without taking adjacent pieces
  if (A <= 8 && B <= 8) {
    printf("Yay! \n");
    return 0;
  } else {
    printf(":( \n");
    return 0;
  }
}
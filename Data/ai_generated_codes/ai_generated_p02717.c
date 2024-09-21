#include <stdio.h>

int main() {
  // Declare variables to store the integers in the boxes
  int X, Y, Z;

  // Read the integers from the input
  scanf("%d %d %d", &X, &Y, &Z);

  // Swap the contents of boxes A and B
  int temp = X;
  X = Y;
  Y = temp;

  // Swap the contents of boxes A and C
  temp = X;
  X = Z;
  Z = temp;

  // Print the final contents of the boxes
  printf("%d %d %d\n", X, Y, Z);

  return 0;
}
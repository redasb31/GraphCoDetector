#include <stdio.h>

int main() {
  // Declare variables for the number of sockets per power strip (A) and the desired number of empty sockets (B).
  int A, B;

  // Read the input values for A and B.
  scanf("%d %d", &A, &B);

  // Calculate the minimum number of power strips required.
  // Since we start with one socket and need B sockets, we need B - 1 additional sockets.
  // We can use power strips with A sockets to get the desired number of sockets.
  // We divide the required number of additional sockets (B - 1) by the number of sockets per power strip (A) and round up to the nearest integer using the ceiling function.
  int powerStripsRequired = (B - 1 + A - 1) / A; // Add A - 1 to B - 1 to ensure rounding up to the nearest integer.

  // Print the minimum number of power strips required.
  printf("%d\n", powerStripsRequired);

  return 0;
}
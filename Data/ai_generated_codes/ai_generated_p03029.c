#include <stdio.h>

int main() {
  // Declare variables to store the number of apples and pieces
  int A, P;

  // Read input from the user
  scanf("%d %d", &A, &P);

  // Calculate the total number of apple pieces
  int totalPieces = P + 3 * A;

  // Calculate the maximum number of apple pies
  int pies = totalPieces / 2;

  // Print the result
  printf("%d\n", pies);

  return 0;
}
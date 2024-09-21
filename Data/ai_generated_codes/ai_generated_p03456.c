#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables to store the input integers
  int a, b;

  // Read the input integers from the user
  scanf("%d %d", &a, &b);

  // Calculate the concatenated number
  int concatenatedNumber = a * 100 + b;

  // Calculate the square root of the concatenated number
  double squareRoot = sqrt(concatenatedNumber);

  // Check if the square root is an integer
  if (squareRoot == (int)squareRoot) {
    // If the square root is an integer, the concatenated number is a square
    printf("Yes\n");
  } else {
    // If the square root is not an integer, the concatenated number is not a square
    printf("No\n");
  }

  return 0;
}
#include <stdio.h>

int main() {
  // Declare variables to store the two integers
  int a, b;

  // Read the two integers from the standard input
  scanf("%d %d", &a, &b);

  // Calculate the product of the two integers
  int product = a * b;

  // Check if the product is even or odd
  if (product % 2 == 0) {
    printf("Even\n"); // Print "Even" if the product is even
  } else {
    printf("Odd\n"); // Print "Odd" if the product is odd
  }

  return 0; // Return 0 to indicate successful execution
}
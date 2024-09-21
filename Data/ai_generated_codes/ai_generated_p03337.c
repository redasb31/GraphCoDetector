#include <stdio.h>

int main() {
  // Declare variables to store input integers
  int A, B;

  // Read input values from the user
  scanf("%d %d", &A, &B);

  // Calculate the sum, difference, and product of A and B
  int sum = A + B;
  int difference = A - B;
  int product = A * B;

  // Find the largest value among sum, difference, and product
  int largest = sum; // Initialize largest to sum
  if (difference > largest) {
    largest = difference;
  }
  if (product > largest) {
    largest = product;
  }

  // Print the largest value
  printf("%d\n", largest);

  return 0;
}
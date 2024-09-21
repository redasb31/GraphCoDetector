#include <stdio.h>

int main() {
  // Declare variables to store the input integers
  int A, B;

  // Read the input values for A and B
  scanf("%d %d", &A, &B);

  // Calculate the results of A + B, A - B, and A × B
  int sum = A + B;
  int difference = A - B;
  int product = A * B;

  // Find the largest number among the calculated results
  int largest = sum;
  if (difference > largest) {
    largest = difference;
  }
  if (product > largest) {
    largest = product;
  }

  // Print the largest number along with a descriptive message
  printf("The largest number among A + B = %d, A - B = %d, and A ×B = %d is %d.\n", sum, difference, product, largest);

  return 0;
}
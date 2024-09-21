#include <stdio.h>

int main() {
  // Declare variables for the input values
  long long int A;
  double B;

  // Read the input values from the user
  scanf("%lld %lf", &A, &B);

  // Calculate the product of A and B
  double product = A * B;

  // Truncate the fractional part of the product
  long long int result = (long long int) product;

  // Print the truncated result as an integer
  printf("%lld\n", result);

  return 0;
}
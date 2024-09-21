#include <stdio.h>
#include <math.h>

int main() {
  // Declare the variable to store the input value X
  long long int X;

  // Read the input value X from the standard input
  scanf("%lld", &X);

  // Calculate the fifth root of X
  long long int A = (long long int) round(pow(X, 1.0 / 5));

  // Find the value of B by solving the equation A^5 - B^5 = X for B
  long long int B = (long long int) round(pow(A * A * A * A * A - X, 1.0 / 5));

  // Print the values of A and B with a space in between
  printf("%lld %lld\n", A, B);

  return 0;
}
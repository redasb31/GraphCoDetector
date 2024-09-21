// This code calculates the maximum possible length of a sequence of integers
// satisfying the given conditions.
// The sequence A needs to:
//  - Consist of integers between X and Y (inclusive).
//  - For each 1 ≤ i ≤ |A|-1, A_i+1 is a multiple of A_i and strictly greater than A_i.

#include <stdio.h>
#include <limits.h>

int main() {
  long long X, Y;
  scanf("%lld %lld", &X, &Y); // Input the range of integers (X, Y).

  int maxLength = 1; // Initialize the maximum length to 1.
  long long currentNumber = X; // Start with the smallest integer in the range.

  // Loop until the current number exceeds the upper bound (Y).
  while (currentNumber <= Y) {
    maxLength++; // Increment the maximum length.
    currentNumber *= 2; // Double the current number (ensuring it's a multiple).
  }

  printf("%d\n", maxLength - 1); // Print the maximum possible length (excluding the initial number).

  return 0;
}
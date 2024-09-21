#include <stdio.h>
#include <limits.h>

int main() {
  // Read the number of integers.
  int N;
  scanf("%d", &N);

  // Initialize the product to 1.
  long long product = 1;

  // Read the integers and multiply them.
  for (int i = 0; i < N; i++) {
    long long A;
    scanf("%lld", &A);

    // Check if the product overflows.
    if (product > LLONG_MAX / A || product < LLONG_MIN / A) {
      // If it overflows, set the product to -1 and break the loop.
      product = -1;
      break;
    } else {
      // Otherwise, multiply the product by the current integer.
      product *= A;
    }
  }

  // Print the product or -1 if it overflowed.
  printf("%lld\n", product);

  return 0;
}
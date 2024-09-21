#include <stdio.h>

int main() {
  // Declare variables for the input number N and the base K.
  long long N;
  int K;

  // Read the input values from the standard input.
  scanf("%lld %d", &N, &K);

  // Initialize a counter for the number of digits.
  int digitCount = 0;

  // Loop until N becomes 0, dividing N by K in each iteration.
  while (N != 0) {
    // Increment the digit count for each iteration.
    digitCount++;
    // Divide N by K to move to the next digit in base K.
    N /= K;
  }

  // Print the calculated number of digits.
  printf("%d\n", digitCount);

  return 0;
}
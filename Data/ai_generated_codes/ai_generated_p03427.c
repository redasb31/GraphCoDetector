#include <stdio.h>

int main() {
  // Declare the variable to store the input number.
  long long int N;

  // Read the input number from the standard input.
  scanf("%lld", &N);

  // Initialize the maximum sum to 0.
  int max_sum = 0;

  // Iterate through each digit of the number.
  while (N > 0) {
    // Calculate the sum of the digits.
    max_sum += N % 10;
    // Remove the last digit.
    N /= 10;
  }

  // Print the maximum sum of the digits.
  printf("%d\n", max_sum);

  return 0;
}
#include <stdio.h>

int main() {
  int x, sum, digit;

  // Loop to read input until a zero is encountered
  while (1) {
    scanf("%d", &x);

    // Break the loop if the input is zero
    if (x == 0) {
      break;
    }

    // Initialize the sum to zero
    sum = 0;

    // Loop to calculate the sum of digits
    while (x > 0) {
      // Extract the last digit of the number
      digit = x % 10;

      // Add the digit to the sum
      sum += digit;

      // Remove the last digit from the number
      x /= 10;
    }

    // Print the sum of digits
    printf("%d\n", sum);
  }

  return 0;
}
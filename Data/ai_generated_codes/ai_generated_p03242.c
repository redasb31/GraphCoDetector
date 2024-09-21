#include <stdio.h>

int main() {
  // Declare an integer variable to store the input.
  int n;

  // Read the input from the user.
  scanf("%d", &n);

  // Declare integer variables to store the digits of the input number.
  int hundreds, tens, ones;

  // Extract the digits of the input number.
  hundreds = n / 100;
  tens = (n % 100) / 10;
  ones = n % 10;

  // Replace the digits as per the problem statement.
  if (hundreds == 1) {
    hundreds = 9;
  } else if (hundreds == 9) {
    hundreds = 1;
  }
  if (tens == 1) {
    tens = 9;
  } else if (tens == 9) {
    tens = 1;
  }
  if (ones == 1) {
    ones = 9;
  } else if (ones == 9) {
    ones = 1;
  }

  // Reconstruct the number from the replaced digits.
  int result = hundreds * 100 + tens * 10 + ones;

  // Print the result.
  printf("%d\n", result);

  return 0;
}
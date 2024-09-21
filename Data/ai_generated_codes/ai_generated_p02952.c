#include <stdio.h>

int main() {
  // Declare an integer variable 'n' to store the input number.
  int n;

  // Read the input number 'n' from the user.
  scanf("%d", &n);

  // Declare an integer variable 'count' to count the number of integers with an odd number of digits.
  int count = 0;

  // Iterate from 1 to 'n' using a for loop.
  for (int i = 1; i <= n; i++) {
    // Declare an integer variable 'digit_count' to count the number of digits in the current integer 'i'.
    int digit_count = 0;

    // Calculate the number of digits in the current integer 'i' by repeatedly dividing by 10 until it becomes 0.
    int temp = i;
    while (temp > 0) {
      digit_count++;
      temp /= 10;
    }

    // Check if the number of digits is odd.
    if (digit_count % 2 != 0) {
      // Increment the count if the number of digits is odd.
      count++;
    }
  }

  // Print the count of integers with an odd number of digits.
  printf("%d\n", count);

  return 0;
}
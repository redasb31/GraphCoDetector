#include <stdio.h>

int main() {
  // Declare a variable to store the input integer.
  int N;

  // Read the input integer from the user.
  scanf("%d", &N);

  // Declare a variable to store the count of '2's.
  int count = 0;

  // Iterate through each digit of the integer.
  while (N > 0) {
    // Extract the last digit of the integer.
    int digit = N % 10;

    // Increment the count if the digit is '2'.
    if (digit == 2) {
      count++;
    }

    // Remove the last digit from the integer.
    N /= 10;
  }

  // Print the count of '2's.
  printf("%d\n", count);

  return 0;
}
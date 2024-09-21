#include <stdio.h>

int main() {
  int a, b;

  // Loop through all input cases until EOF is encountered
  while (scanf("%d %d", &a, &b) != EOF) {
    // Calculate the sum of a and b
    int sum = a + b;

    // Initialize a counter for the number of digits
    int digit_count = 0;

    // Handle the case where sum is 0 (special case)
    if (sum == 0) {
      digit_count = 1;
    } else {
      // Iterate through the sum, counting the digits
      while (sum > 0) {
        sum /= 10;
        digit_count++;
      }
    }

    // Print the number of digits of the sum
    printf("%d\n", digit_count);
  }

  return 0;
}
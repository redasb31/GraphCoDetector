#include <stdio.h>

// Function to calculate the sum of digits of a number
int sum_of_digits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  int N, A, B;
  scanf("%d %d %d", &N, &A, &B); // Read input values

  int sum = 0; // Initialize the sum to 0

  // Iterate through each number from 1 to N
  for (int i = 1; i <= N; i++) {
    // Calculate the sum of digits of the current number
    int digit_sum = sum_of_digits(i);

    // Check if the sum of digits is within the range A to B
    if (digit_sum >= A && digit_sum <= B) {
      // Add the current number to the sum
      sum += i;
    }
  }

  // Print the final sum
  printf("%d\n", sum);

  return 0;
}
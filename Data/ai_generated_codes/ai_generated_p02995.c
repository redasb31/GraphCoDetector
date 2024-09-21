#include <stdio.h>

// Function to check if a number is divisible by either c or d
int isDivisible(long long int num, long long int c, long long int d) {
  // Check if the number is divisible by c or d
  if (num % c == 0 || num % d == 0) {
    return 1; // Number is divisible by either c or d
  } else {
    return 0; // Number is not divisible by either c or d
  }
}

int main() {
  // Declare variables to store the input values
  long long int a, b, c, d;

  // Read the input values from the user
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

  // Initialize a counter to keep track of the number of integers satisfying the condition
  int count = 0;

  // Iterate through all the integers between a and b (inclusive)
  for (long long int i = a; i <= b; i++) {
    // Check if the current number is not divisible by either c or d
    if (!isDivisible(i, c, d)) {
      // Increment the counter if the condition is satisfied
      count++;
    }
  }

  // Print the final count
  printf("%d\n", count);

  return 0;
}
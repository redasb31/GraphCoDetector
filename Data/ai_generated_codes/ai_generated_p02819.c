#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
  // Handle special cases: 0 and 1 are not prime
  if (num <= 1) {
    return false;
  }
  // Check divisibility from 2 to the square root of the number
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  // If no divisors found, the number is prime
  return true;
}

int main() {
  int x;
  // Read the input value
  scanf("%d", &x);

  // Iterate from X onwards, checking each number for primality
  while (true) {
    if (is_prime(x)) {
      // If a prime number is found, print it and break the loop
      printf("%d\n", x);
      break;
    }
    // Increment X to check the next number
    x++;
  }
  return 0;
}
#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  scanf("%d", &n); // Read the input integer

  printf("%d: ", n); // Print the integer and a colon

  // Iterate from 2 to the square root of n
  for (int i = 2; i <= sqrt(n); i++) {
    // Check if the current number is prime
    if (isPrime(i)) {
      // Check if the current prime number is a factor of n
      while (n % i == 0) {
        printf(" %d", i); // Print the prime factor
        n /= i; // Divide n by the prime factor
      }
    }
  }

  // If n is greater than 1, it is itself a prime factor
  if (n > 1) {
    printf(" %d", n); 
  }

  printf("\n"); // Print a newline character
  return 0;
}
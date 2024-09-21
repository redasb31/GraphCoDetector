#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
  if (num <= 1) {
    return false;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// Function to find the length of the prime gap containing a given number
int prime_gap_length(int k) {
  // Check if k is a prime number
  if (is_prime(k)) {
    return 0;
  }

  // Find the previous prime number
  int prev_prime = k - 1;
  while (!is_prime(prev_prime)) {
    prev_prime--;
  }

  // Find the next prime number
  int next_prime = k + 1;
  while (!is_prime(next_prime)) {
    next_prime++;
  }

  // Calculate the length of the prime gap
  return next_prime - prev_prime - 1;
}

int main() {
  int k;
  while (1) {
    scanf("%d", &k);
    if (k == 0) {
      break;
    }
    printf("%d\n", prime_gap_length(k));
  }
  return 0;
}
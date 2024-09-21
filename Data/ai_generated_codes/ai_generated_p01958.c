#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to count the number of prime factors of a number
int count_prime_factors(int n) {
  int count = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      count++;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    count++;
  }
  return count;
}

// Function to check if a number is a prime-factor prime
int is_prime_factor_prime(int n) {
  int num_prime_factors = count_prime_factors(n);
  return is_prime(num_prime_factors);
}

int main() {
  int l, r;

  // Input the interval [l, r]
  scanf("%d %d", &l, &r);

  // Count the number of prime-factor prime numbers in the interval
  int count = 0;
  for (int i = l; i <= r; i++) {
    if (is_prime_factor_prime(i)) {
      count++;
    }
  }

  // Output the count
  printf("%d\n", count);

  return 0;
}
#include <stdio.h>

#define MOD 1000000007

// Function to calculate modular exponentiation
long long int power(long long int base, long long int exp) {
  long long int result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    exp /= 2;
  }
  return result;
}

int main() {
  long long int n, k;
  scanf("%lld %lld", &n, &k); // Read n and k from input

  // Calculate the number of ways to distribute the balls
  long long int ways = power(k, n); // Each ball has k choices

  printf("%lld\n", ways); // Print the result modulo 10^9+7

  return 0;
}
#include <stdio.h>

#define MOD 1000000007

// Function to calculate factorial modulo MOD
long long factorial(long long n) {
  long long fact = 1;
  for (long long i = 2; i <= n; i++) {
    fact = (fact * i) % MOD;
  }
  return fact;
}

// Function to calculate the number of ways to put balls into boxes
long long countWays(long long n, long long k) {
  // Calculate (n + k - 1)C(k - 1) using factorial
  return (factorial(n + k - 1) * (factorial(k - 1) * factorial(n)) % MOD) / (factorial(k - 1) * factorial(n)) % MOD;
}

int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);

  // Calculate and print the number of ways modulo MOD
  printf("%lld\n", countWays(n, k));

  return 0;
}
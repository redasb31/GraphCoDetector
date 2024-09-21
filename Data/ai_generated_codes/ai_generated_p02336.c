#include <stdio.h>

#define MOD 1000000007

// Function to calculate the factorial of a number modulo MOD
long long factorial(long long n) {
  long long result = 1;
  for (long long i = 2; i <= n; i++) {
    result = (result * i) % MOD;
  }
  return result;
}

// Function to calculate the number of ways to put n balls into k boxes,
// where each box must contain at least one ball
long long count_ways(long long n, long long k) {
  // If the number of balls is less than the number of boxes,
  // it's impossible to put at least one ball in each box
  if (n < k) {
    return 0;
  }

  // Calculate the factorial of (n-1) and (k-1)
  long long fact_n_minus_1 = factorial(n - 1);
  long long fact_k_minus_1 = factorial(k - 1);

  // Calculate the number of ways to put n balls into k boxes
  // using the stars and bars method
  return (fact_n_minus_1 * fact_k_minus_1) % MOD;
}

int main() {
  long long n, k;

  // Read the number of balls and boxes
  scanf("%lld %lld", &n, &k);

  // Calculate and print the number of ways
  printf("%lld\n", count_ways(n, k));

  return 0;
}
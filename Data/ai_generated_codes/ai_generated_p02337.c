#include <stdio.h>

#define MOD 1000000007

// Function to calculate the modular exponentiation
long long int power(long long int x, long long int y) {
  long long int result = 1;
  x %= MOD;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % MOD;
    }
    y >>= 1;
    x = (x * x) % MOD;
  }
  return result;
}

// Function to calculate the number of ways to put n balls into k boxes
long long int countWays(long long int n, long long int k) {
  // Calculate the number of ways to put n balls into k boxes using the stars and bars method
  // We need n-1 bars to separate the n balls into k boxes
  long long int ways = power(k, n);
  return ways;
}

int main() {
  long long int n, k;

  // Input the number of balls and boxes
  scanf("%lld %lld", &n, &k);

  // Calculate the number of ways and print the result modulo 10^9+7
  printf("%lld\n", countWays(n, k) % MOD);

  return 0;
}
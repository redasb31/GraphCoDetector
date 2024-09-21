#include <stdio.h>

#define MOD 1000000007

// Function to calculate the factorial of a number modulo MOD
long long factorial(long long n) {
  if (n == 0) {
    return 1;
  }
  long long result = 1;
  for (long long i = 1; i <= n; i++) {
    result = (result * i) % MOD;
  }
  return result;
}

// Function to calculate the number of ways to choose r items from n items modulo MOD
long long choose(long long n, long long r) {
  if (r > n || r < 0) {
    return 0;
  }
  return (factorial(n) * (factorial(n - r) * factorial(r)) % MOD) % MOD;
}

int main() {
  long long n, a, b;
  scanf("%lld %lld %lld", &n, &a, &b);

  long long total_bouquets = 0;

  // Calculate the number of bouquets for each possible size
  for (long long i = 1; i <= n; i++) {
    if (i != a && i != b) {
      total_bouquets = (total_bouquets + choose(n, i)) % MOD;
    }
  }

  printf("%lld\n", total_bouquets);

  return 0;
}
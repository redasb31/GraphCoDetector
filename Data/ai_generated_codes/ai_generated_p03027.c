#include <stdio.h>

#define MOD 1000003

// Function to calculate the product of the arithmetic progression
long long product_of_ap(long long x, long long d, long long n) {
  // Handle the case when n is 0
  if (n == 0) {
    return 1;
  }

  // Calculate the product modulo 1000003
  long long product = 1;
  for (long long i = 0; i < n; i++) {
    product = (product * (x + i * d)) % MOD;
  }
  return product;
}

int main() {
  int Q;
  scanf("%d", &Q);

  // Process each query
  for (int i = 0; i < Q; i++) {
    long long x, d, n;
    scanf("%lld %lld %lld", &x, &d, &n);
    long long result = product_of_ap(x, d, n);
    printf("%lld\n", result);
  }

  return 0;
}
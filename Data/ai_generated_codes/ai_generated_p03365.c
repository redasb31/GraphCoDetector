#include <stdio.h>
#define MOD 1000000007

long long int factorial(long long int n) {
  if (n == 0) {
    return 1;
  } else {
    return (n * factorial(n - 1)) % MOD;
  }
}

int main() {
  long long int n;
  scanf("%lld", &n);

  // Calculate the factorial of (n - 1)
  long long int fact_n_minus_1 = factorial(n - 1);

  // Calculate the sum of the scores for all permutations
  long long int sum = 0;
  for (long long int i = 1; i <= n - 1; i++) {
    // Calculate the number of permutations where machine i is the last one operated
    long long int permutations = fact_n_minus_1 / factorial(i - 1) / factorial(n - i);
    // The score for these permutations is i
    sum = (sum + (permutations * i) % MOD) % MOD;
  }

  printf("%lld\n", sum);
  return 0;
}
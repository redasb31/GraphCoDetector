#include <stdio.h>

#define MOD 1000000007

// Function to calculate the binomial coefficient (n choose k) modulo MOD
long long binom(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  long long result = 1;
  for (int i = 0; i < k; ++i) {
    result = (result * (n - i)) % MOD;
    result = (result * (i + 1)) % MOD; // Inverse modulo for division
  }
  return result;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  // Number of ways to distribute n indistinguishable balls into k distinguishable boxes
  // is (n + k - 1) choose (k - 1)
  long long answer = binom(n + k - 1, k - 1);
  printf("%lld\n", answer);

  return 0;
}
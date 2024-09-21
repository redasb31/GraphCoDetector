#include <stdio.h>

#define MOD 1000000007

// Function to calculate factorial modulo MOD
long long factorial(int n) {
  long long fact = 1;
  for (int i = 2; i <= n; i++) {
    fact = (fact * i) % MOD;
  }
  return fact;
}

// Function to calculate the number of ways to put n indistinguishable balls into k indistinguishable boxes, where each box must contain at least one ball
long long countWays(int n, int k) {
  // If the number of balls is less than the number of boxes, it's not possible to put at least one ball in each box
  if (n < k) {
    return 0;
  }
  // Calculate (n - 1)C(k - 1) which represents the number of ways to divide n balls into k groups, where each group has at least one ball
  return factorial(n - 1) / (factorial(k - 1) * factorial(n - k)) % MOD;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%lld\n", countWays(n, k));
  return 0;
}
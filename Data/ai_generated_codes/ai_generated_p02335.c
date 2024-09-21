#include <stdio.h>

#define MOD 1000000007

// Function to calculate factorial modulo MOD
long long factorial(int n) {
  long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = (fact * i) % MOD;
  }
  return fact;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  // If the number of balls is greater than the number of boxes, there are no valid arrangements
  if (n > k) {
    printf("0\n");
    return 0;
  }

  // Calculate the number of ways to choose k balls from n
  long long ways = factorial(k) / (factorial(n) * factorial(k - n));

  // Print the result modulo MOD
  printf("%lld\n", ways % MOD);

  return 0;
}
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

  // If number of balls is greater than number of boxes, it's impossible
  if (n > k) {
    printf("0\n");
  } else {
    // Calculate the number of ways using factorials
    long long ways = factorial(k) / (factorial(n) * factorial(k - n));
    printf("%lld\n", ways % MOD);
  }

  return 0;
}
#include <stdio.h>

#define MOD 1000000007

// Function to calculate the factorial of a number modulo MOD
long long factorial(int n) {
  long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = (fact * i) % MOD;
  }
  return fact;
}

// Function to calculate the number of ways to put n balls into k boxes
// where each ball is indistinguishable, each box is indistinguishable,
// each box can contain at most one ball, and no ball remains outside
long long count_ways(int n, int k) {
  if (n > k) {
    return 0;
  } else {
    return factorial(k) / (factorial(n) * factorial(k - n));
  }
}

int main() {
  int n, k;

  // Read the number of balls and boxes from the user
  scanf("%d %d", &n, &k);

  // Calculate the number of ways to put the balls into the boxes
  long long ways = count_ways(n, k);

  // Print the number of ways modulo 10^9+7
  printf("%lld\n", ways % MOD);

  return 0;
}
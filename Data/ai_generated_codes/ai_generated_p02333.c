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

// Function to calculate the number of ways to put n balls into k boxes,
// where each ball is distinguishable, each box is distinguishable, and each box must contain at least one ball.
long long balls_and_boxes(int n, int k) {
  // Calculate the total number of ways to put n balls into k boxes without any restrictions
  long long total_ways = factorial(n) / factorial(k) / factorial(n - k);

  // Calculate the number of ways to put n balls into k boxes where some boxes can be empty
  long long empty_ways = factorial(n + k - 1) / factorial(k) / factorial(n - 1);

  // Subtract the number of ways with empty boxes from the total number of ways
  return (total_ways - empty_ways + MOD) % MOD;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%lld\n", balls_and_boxes(n, k));
  return 0;
}
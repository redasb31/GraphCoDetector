#include <stdio.h>

#define MOD 998244353

// Function to calculate the number of ways to move the pieces
long long countWays(int n, int a, int b) {
  // Base case: if the pieces are already at the desired positions
  if (a == b) {
    return 1;
  }

  // If the pieces are already at the desired positions
  if (a == b) {
    return 1;
  }

  // Calculate the number of ways to reach the desired positions
  // by moving the pieces independently
  long long ways = 0;
  for (int i = 0; i <= a; i++) {
    // Calculate the number of ways to move the first piece to position i
    long long ways1 = 1;
    for (int j = 0; j < i; j++) {
      ways1 = (ways1 * (n - j)) % MOD;
    }

    // Calculate the number of ways to move the second piece to position a - i
    long long ways2 = 1;
    for (int j = 0; j < a - i; j++) {
      ways2 = (ways2 * (n - j)) % MOD;
    }

    // Add the product of ways1 and ways2 to the total number of ways
    ways = (ways + ways1 * ways2) % MOD;
  }

  // Calculate the number of ways to reach the desired positions
  // by moving the pieces together
  long long ways3 = 1;
  for (int i = 0; i < b; i++) {
    ways3 = (ways3 * (n - i)) % MOD;
  }

  // Add the number of ways to reach the desired positions by moving the pieces together
  ways = (ways + ways3) % MOD;

  // Return the total number of ways
  return ways;
}

int main() {
  int n, a, b;
  // Read the input
  scanf("%d %d %d", &n, &a, &b);

  // Calculate and print the number of ways to move the pieces
  printf("%lld\n", countWays(n, a, b));
  return 0;
}
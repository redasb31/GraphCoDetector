#include <stdio.h>

#define MOD 1000000007

long long int power(long long int x, long long int y) {
  long long int result = 1;
  x %= MOD;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % MOD;
    }
    y >>= 1;
    x = (x * x) % MOD;
  }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);

  long long int count = 0;  // Stores the number of distinct positions
  long long int x = 10;    // Base of the power
  long long int y = 100;  // Power to which the base is raised

  // Iterate from 1 to n, each iteration corresponds to the removal of a checker
  for (int i = 1; i <= n; i++) {
    long long int current_position = power(x, (y * i) % MOD); // Calculate current position
    count = (count + current_position) % MOD;        // Add current position to count
  }

  // Calculate the total number of distinct positions
  count = (count * power(2, n - 1)) % MOD;  // Multiply by 2^(n-1) for all possible moves
  printf("%lld\n", count);
  return 0;
}
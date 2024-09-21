#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of ways the knight can reach the square (X, Y)
long long countWays(int X, int Y) {
  // Base case: If the knight is already at the destination
  if (X == 0 && Y == 0) {
    return 1;
  }
  // Base case: If the destination is unreachable
  if (X < 0 || Y < 0 || (X + Y) % 3 != 0) {
    return 0;
  }

  // Recursive calls to calculate the number of ways from the previous possible positions
  return (countWays(X - 1, Y - 2) + countWays(X - 2, Y - 1)) % MOD;
}

int main() {
  int X, Y;
  scanf("%d %d", &X, &Y);

  // Calculate the number of ways
  long long ways = countWays(X, Y);

  // Print the result modulo 10^9 + 7
  printf("%lld\n", ways);

  return 0;
}
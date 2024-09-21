#include <stdio.h>

int main() {
  // N: Number of even balls
  // M: Number of odd balls
  int N, M;
  scanf("%d %d", &N, &M);

  // Calculate the number of ways to choose two even balls
  long long evenEven = (N * (N - 1)) / 2;

  // Calculate the number of ways to choose two odd balls
  long long oddOdd = (M * (M - 1)) / 2;

  // The total number of ways to choose two balls with an even sum
  // is the sum of choosing two even balls and choosing two odd balls.
  long long totalWays = evenEven + oddOdd;

  // Print the result
  printf("%lld\n", totalWays);

  return 0;
}
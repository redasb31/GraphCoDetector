#include <stdio.h>

int main() {
  // Declare variables for board dimensions.
  long long H, W;

  // Read board dimensions from standard input.
  scanf("%lld %lld", &H, &W);

  // Calculate the maximum number of squares the bishop can reach.
  // This is the sum of the number of squares on the diagonals that the bishop can reach.
  long long reachable_squares = H + W - 1;

  // Print the result to standard output.
  printf("%lld\n", reachable_squares);

  return 0;
}
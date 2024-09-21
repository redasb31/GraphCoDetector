#include <stdio.h>

int main() {
  // Declare variables to store the number of balls and the number of persons.
  int N, K;

  // Read the number of balls (N) and the number of persons (K) from the user.
  scanf("%d %d", &N, &K);

  // Calculate the maximum difference in the number of balls received.
  // The maximum difference occurs when one person gets as many balls as possible
  // and the remaining people get the minimum number of balls (1 each).
  int max_difference = N - (K - 1);

  // Print the maximum difference.
  printf("%d\n", max_difference);

  return 0;
}
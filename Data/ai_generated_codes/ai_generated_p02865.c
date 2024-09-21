#include <stdio.h>

int main() {
  // Declare the variable to store the input integer
  int N;

  // Read the input integer from the standard input
  scanf("%d", &N);

  // Calculate the number of ways to choose two distinct positive integers
  // This is simply the number of integers less than N/2
  int ways = (N / 2) - 1;

  // Print the result
  printf("%d\n", ways);

  return 0;
}
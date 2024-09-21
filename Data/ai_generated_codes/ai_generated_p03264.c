#include <stdio.h>

int main() {
  // Declare the variable to store the input value K
  int K;

  // Read the input value K from the standard input
  scanf("%d", &K);

  // Calculate the number of even numbers between 1 and K
  int evenCount = K / 2;

  // Calculate the number of odd numbers between 1 and K
  int oddCount = (K + 1) / 2;

  // Calculate the number of ways to choose a pair of an even and an odd number
  int numWays = evenCount * oddCount;

  // Print the result to the standard output
  printf("%d\n", numWays);

  return 0;
}
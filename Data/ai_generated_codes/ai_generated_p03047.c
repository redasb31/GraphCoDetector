/*
 * This program calculates the number of ways to choose K consecutive integers from a set of N integers.
 *
 * Input:
 *   N: The total number of integers.
 *   K: The number of consecutive integers to choose.
 *
 * Output:
 *   The number of ways to choose K consecutive integers.
 */
#include <stdio.h>

int main() {
  int N, K;

  // Input the number of integers and the number of consecutive integers to choose.
  scanf("%d %d", &N, &K);

  // If K is greater than N, there are no ways to choose K consecutive integers.
  if (K > N) {
    printf("0\n");
    return 0;
  }

  // There are N - K + 1 ways to choose K consecutive integers.
  printf("%d\n", N - K + 1);

  return 0;
}
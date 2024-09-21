/*
 * This program calculates the depth of snow cover given the heights of two adjacent towers.
 * 
 * Input:
 *  - a: The height of the western tower (meters).
 *  - b: The height of the eastern tower (meters).
 *
 * Output:
 *  - The depth of the snow cover (meters).
 */

#include <stdio.h>

int main() {
  int a, b;

  // Read the heights of the two towers from standard input.
  scanf("%d %d", &a, &b);

  // Calculate the difference in height between the two towers.
  int heightDifference = b - a;

  // Calculate the depth of the snow cover.
  int snowDepth = heightDifference - 1;

  // Print the depth of the snow cover.
  printf("%d\n", snowDepth);

  return 0;
}
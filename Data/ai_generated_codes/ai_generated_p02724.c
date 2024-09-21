/*
 * This program calculates the maximum happiness points Takahashi can earn by exchanging his money.
 *
 * Input:
 *  X: The amount of money Takahashi has (in yen).
 *
 * Output:
 *  The maximum number of happiness points Takahashi can earn.
 */
#include <stdio.h>

int main() {
  int X;

  // Read the amount of money Takahashi has.
  scanf("%d", &X);

  // Calculate the maximum number of happiness points.
  int happiness_points = 0;
  happiness_points += X / 500 * 1000; // Happiness points from 500-yen coins.
  X %= 500; // Remaining yen after exchanging for 500-yen coins.
  happiness_points += X / 5 * 5; // Happiness points from 5-yen coins.

  // Print the maximum number of happiness points.
  printf("%d\n", happiness_points);

  return 0;
}
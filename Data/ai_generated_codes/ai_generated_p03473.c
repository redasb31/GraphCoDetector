// This program calculates the remaining hours until New Year's Eve at a given time on December 30th.

#include <stdio.h>

int main() {
  // Declare a variable to store the input hour.
  int M;

  // Read the input hour from the user.
  scanf("%d", &M);

  // Calculate the remaining hours until New Year's Eve.
  // There are 24 hours in a day, and we are on December 30th, so we have 24 hours left.
  // We then subtract the current hour to get the remaining hours.
  int remaining_hours = 24 - M;

  // Print the result.
  printf("%d\n", remaining_hours);

  return 0;
}
#include <stdio.h>

int main() {
  // Declare variables for the number of dresses and the frequency of parties.
  int dresses, parties;

  // Read the number of dresses and the frequency of parties from the user.
  scanf("%d %d", &dresses, &parties);

  // Calculate the maximum frequency of wearing the most reused dress.
  // This is simply the quotient of the number of parties and the number of dresses.
  int max_frequency = parties / dresses;

  // Print the maximum frequency.
  printf("%d\n", max_frequency);

  return 0;
}
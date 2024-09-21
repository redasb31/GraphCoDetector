#include <stdio.h>

int main() {
  // N is the number of the next ABC to be held
  int N;
  scanf("%d", &N);

  // We need to find the smallest number greater than or equal to N where all digits are the same
  int earliestABC = N;

  // Loop until we find a number where all digits are the same
  while (1) {
    // Get the first digit of the number
    int firstDigit = earliestABC / 100;
    // Check if all digits are the same
    if (earliestABC / 10 % 10 == firstDigit && earliestABC % 10 == firstDigit) {
      // If all digits are the same, break the loop
      break;
    } else {
      // Otherwise, increment the number
      earliestABC++;
    }
  }

  // Print the earliest ABC where Kurohashi can make his debut
  printf("%d\n", earliestABC);

  return 0;
}
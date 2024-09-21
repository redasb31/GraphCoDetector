#include <stdio.h>

int main() {
  int budget, floor, floors, sum;

  // Loop through each dataset until a zero is encountered
  while (1) {
    scanf("%d", &budget);

    // End of input
    if (budget == 0) {
      break;
    }

    // Initialize floor and floors to 1
    floor = 1;
    floors = 1;
    sum = floor;

    // Find the maximum number of floors with the given budget
    while (sum < budget) {
      floor++;
      floors++;
      sum += floor;
    }

    // Adjust the number of floors if the sum is greater than the budget
    if (sum > budget) {
      floors--;
      sum -= floor;
    }

    // Print the starting floor and number of floors
    printf("%d %d\n", floor - floors + 1, floors);
  }

  return 0;
}
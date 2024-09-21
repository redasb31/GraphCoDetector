// This program calculates the total amount of money DISCO-Kun earned in two competitions.
// The program takes two inputs: X and Y, which represent the positions DISCO-Kun took in
// the Coding Contest and Robot Maneuver, respectively.
//
// The prize money for each competition is as follows:
// - 3rd place: 100000 yen
// - 2nd place: 200000 yen
// - 1st place: 300000 yen
//
// Additionally, if DISCO-Kun wins both competitions, he receives an additional 400000 yen.
//
// The program outputs the total amount of money DISCO-Kun earned.

#include <stdio.h>

int main() {
  // Declare variables to store the positions in the two competitions.
  int X, Y;

  // Get the positions from the user.
  scanf("%d %d", &X, &Y);

  // Declare a variable to store the total amount of money earned.
  int total_money = 0;

  // Calculate the prize money for the Coding Contest.
  if (X == 1) {
    total_money += 300000; // 1st place
  } else if (X == 2) {
    total_money += 200000; // 2nd place
  } else if (X == 3) {
    total_money += 100000; // 3rd place
  }

  // Calculate the prize money for the Robot Maneuver.
  if (Y == 1) {
    total_money += 300000; // 1st place
  } else if (Y == 2) {
    total_money += 200000; // 2nd place
  } else if (Y == 3) {
    total_money += 100000; // 3rd place
  }

  // Add the bonus for winning both competitions.
  if (X == 1 && Y == 1) {
    total_money += 400000;
  }

  // Print the total amount of money earned.
  printf("%d\n", total_money);

  return 0;
}
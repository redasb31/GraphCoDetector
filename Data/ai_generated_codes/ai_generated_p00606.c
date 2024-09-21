#include <stdio.h>
#include <stdlib.h>

// Function to calculate the probability of the robot stopping at the battery room
double calculateProbability(int n, char s, char t, char b) {
  // Create a 2D array to represent the house
  char house[3][3] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'}
  };

  // Find the coordinates of the initial room, battery room, and junk room
  int si, sj, ti, tj, bi, bj;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (house[i][j] == s) {
        si = i;
        sj = j;
      }
      if (house[i][j] == t) {
        ti = i;
        tj = j;
      }
      if (house[i][j] == b) {
        bi = i;
        bj = j;
      }
    }
  }

  // Initialize the probability to 0
  double probability = 0.0;

  // Iterate over all possible moves
  for (int i = 0; i < n; i++) {
    // Calculate the probability of reaching the battery room in the current move
    double currentProbability = 1.0;
    for (int j = 0; j < i; j++) {
      currentProbability *= 0.25;
    }

    // Check if the robot is in the battery room
    if (si == ti && sj == tj) {
      // Add the probability of reaching the battery room in the current move
      probability += currentProbability;
      break;
    }

    // Check if the robot is in the junk room
    if (si == bi && sj == bj) {
      // The robot will stay in the junk room, so the probability of reaching the battery room is 0
      break;
    }

    // Check if the robot can move to the north
    if (si > 0) {
      // Calculate the probability of moving to the north
      currentProbability *= 0.25;
      // Update the coordinates of the robot
      si--;
    } else {
      // The robot cannot move to the north
      currentProbability *= 0.75;
    }

    // Check if the robot can move to the south
    if (si < 2) {
      // Calculate the probability of moving to the south
      currentProbability *= 0.25;
      // Update the coordinates of the robot
      si++;
    } else {
      // The robot cannot move to the south
      currentProbability *= 0.75;
    }

    // Check if the robot can move to the east
    if (sj < 2) {
      // Calculate the probability of moving to the east
      currentProbability *= 0.25;
      // Update the coordinates of the robot
      sj++;
    } else {
      // The robot cannot move to the east
      currentProbability *= 0.75;
    }

    // Check if the robot can move to the west
    if (sj > 0) {
      // Calculate the probability of moving to the west
      currentProbability *= 0.25;
      // Update the coordinates of the robot
      sj--;
    } else {
      // The robot cannot move to the west
      currentProbability *= 0.75;
    }
  }

  // Return the probability of the robot stopping at the battery room
  return probability;
}

int main() {
  int n;
  char s, t, b;

  // Read the input
  while (scanf("%d\n%c %c %c\n", &n, &s, &t, &b) == 4 && n != 0) {
    // Calculate the probability of the robot stopping at the battery room
    double probability = calculateProbability(n, s, t, b);

    // Print the probability
    printf("%.8lf\n", probability);
  }

  return 0;
}
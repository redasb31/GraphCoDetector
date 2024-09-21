#include <stdio.h>

// Function to check if two dice are different based on their face values
int areDiceDifferent(int dice1[], int dice2[]) {
  // Sort the face values of both dices in ascending order
  // This allows for a simple comparison of corresponding face values
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      if (dice1[i] > dice1[j]) {
        int temp = dice1[i];
        dice1[i] = dice1[j];
        dice1[j] = temp;
      }
      if (dice2[i] > dice2[j]) {
        int temp = dice2[i];
        dice2[i] = dice2[j];
        dice2[j] = temp;
      }
    }
  }
  // Compare the sorted face values of both dices
  for (int i = 0; i < 6; i++) {
    if (dice1[i] != dice2[i]) {
      return 1; // Dices are different
    }
  }
  return 0; // Dices are not different
}

int main() {
  int n; // Number of dices
  scanf("%d", &n);

  // Array to store the face values of each dice
  int dices[100][6];

  // Read the face values of each dice
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      scanf("%d", &dices[i][j]);
    }
  }

  // Flag to determine if all dices are different
  int allDifferent = 1;

  // Compare each dice with the other dices
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!areDiceDifferent(dices[i], dices[j])) {
        // If any two dices are not different, set the flag to 0
        allDifferent = 0;
      }
    }
  }

  // Print the result
  if (allDifferent) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
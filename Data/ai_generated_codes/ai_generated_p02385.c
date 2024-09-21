#include <stdio.h>

int main() {
  // Declare arrays to store the dice values.
  int dice1[6], dice2[6];

  // Read the values for the first dice.
  for (int i = 0; i < 6; i++) {
    scanf("%d", &dice1[i]);
  }

  // Read the values for the second dice.
  for (int i = 0; i < 6; i++) {
    scanf("%d", &dice2[i]);
  }

  // Compare the dice values.
  int identical = 1; // Assume the dices are identical initially.
  for (int i = 0; i < 6; i++) {
    // If any value differs, set identical to 0.
    if (dice1[i] != dice2[i]) {
      identical = 0;
      break;
    }
  }

  // Print the result.
  if (identical) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
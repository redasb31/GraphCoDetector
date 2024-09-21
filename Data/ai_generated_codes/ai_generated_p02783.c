#include <stdio.h>

int main() {
  // Declare variables to store the monster's health and Serval's attack power.
  int H, A;

  // Read the monster's health and Serval's attack power from the input.
  scanf("%d %d", &H, &A);

  // Calculate the number of attacks needed to defeat the monster.
  int attacks = H / A;

  // If the monster's health is not perfectly divisible by the attack power,
  // Serval needs one extra attack.
  if (H % A != 0) {
    attacks++;
  }

  // Print the number of attacks needed to defeat the monster.
  printf("%d\n", attacks);

  return 0;
}
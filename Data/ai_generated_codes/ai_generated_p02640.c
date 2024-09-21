#include <stdio.h>

int main() {
  // Declare variables to store the number of animals and legs.
  int X, Y;

  // Read the number of animals (X) and legs (Y) from the user.
  scanf("%d %d", &X, &Y);

  // Check if the number of legs is valid for the given number of animals.
  // The number of legs must be at least 2*X (all cranes) and at most 4*X (all turtles).
  if (Y >= 2 * X && Y <= 4 * X && (Y - 2 * X) % 2 == 0) {
    // If the number of legs is valid, print "Yes".
    printf("Yes\n");
  } else {
    // Otherwise, print "No".
    printf("No\n");
  }

  return 0;
}
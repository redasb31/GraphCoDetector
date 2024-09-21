#include <stdio.h>

int main() {
  // Declare variables to store the age and cost of the Ferris wheel.
  int A, B;

  // Read the age and cost from the user.
  scanf("%d %d", &A, &B);

  // Calculate the cost of the Ferris wheel for Takahashi.
  if (A >= 13) {
    // If Takahashi is 13 years old or older, the cost is B yen.
    printf("%d\n", B);
  } else if (A >= 6 && A <= 12) {
    // If Takahashi is between 6 and 12 years old, the cost is half of B yen.
    printf("%d\n", B / 2);
  } else {
    // If Takahashi is 5 years old or younger, the ride is free.
    printf("%d\n", 0);
  }

  return 0;
}
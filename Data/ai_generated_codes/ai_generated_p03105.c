#include <stdio.h>

int main() {
  // Declare variables to store input values
  int A, B, C;

  // Read the input values from the user
  scanf("%d %d %d", &A, &B, &C);

  // Calculate the maximum number of times Takahashi can hear the sound
  int times = B / A;

  // Ensure Takahashi doesn't hear the sound more than C times
  if (times > C) {
    times = C;
  }

  // Print the result
  printf("%d\n", times);

  return 0;
}
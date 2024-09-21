#include <stdio.h>

int main() {
  // Declare a variable to store the age of Takahashi.
  int X;

  // Read the age of Takahashi from the input.
  scanf("%d", &X);

  // Check if Takahashi's age is 3, 5, or 7.
  if (X == 3 || X == 5 || X == 7) {
    // If yes, print YES.
    printf("YES\n");
  } else {
    // If no, print NO.
    printf("NO\n");
  }

  return 0;
}
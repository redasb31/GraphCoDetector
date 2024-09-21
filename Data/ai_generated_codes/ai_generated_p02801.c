#include <stdio.h>

int main() {
  // Declare a variable to store the input character.
  char c;

  // Read the input character from the user.
  scanf("%c", &c);

  // Check if the input character is 'z'.
  // If it is, then print an error message.
  if (c == 'z') {
    printf("Error: Input character cannot be 'z'.\n");
    return 1;
  }

  // If the input character is not 'z', then print the next character in alphabetical order.
  else {
    printf("%c is followed by %c.\n", c, c + 1);
  }

  return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input symbols.
  char S[5];

  // Get the input string from the user.
  scanf("%s", S);

  // Initialize the integer in Takahashi's mind to 0.
  int integer = 0;

  // Iterate over each character in the input string.
  for (int i = 0; i < 4; i++) {
    // If the character is '+', increment the integer by 1.
    if (S[i] == '+') {
      integer++;
    } 
    // If the character is '-', decrement the integer by 1.
    else if (S[i] == '-') {
      integer--;
    }
  }

  // Print the final integer in Takahashi's mind.
  printf("%d\n", integer);

  return 0;
}
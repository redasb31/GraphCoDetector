#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input string.
  char S[101];

  // Read the input string from the user.
  scanf("%s", S);

  // Check if the string is easily playable.
  // We iterate through the string, checking if the characters at odd and even positions meet the conditions.
  int is_playable = 1; // Initialize to true
  for (int i = 0; i < strlen(S); i++) {
    // If the character is at an odd position
    if (i % 2 == 0) {
      // Check if it's L, U, or D
      if (S[i] != 'L' && S[i] != 'U' && S[i] != 'D') {
        is_playable = 0; // If not, set is_playable to false
        break; // No need to continue checking
      }
    } else {
      // If the character is at an even position
      // Check if it's R, U, or D
      if (S[i] != 'R' && S[i] != 'U' && S[i] != 'D') {
        is_playable = 0; // If not, set is_playable to false
        break; // No need to continue checking
      }
    }
  }

  // Print the result based on the is_playable variable
  if (is_playable) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
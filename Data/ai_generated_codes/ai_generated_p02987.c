#include <stdio.h>
#include <string.h>

int main() {
  // Declare a character array to store the input string.
  char S[5];

  // Read the input string from the user.
  scanf("%s", S);

  // Declare variables to count the occurrences of each character.
  int count[26] = {0};

  // Count the occurrences of each character in the input string.
  for (int i = 0; i < 4; i++) {
    count[S[i] - 'A']++;
  }

  // Initialize a variable to keep track of the number of unique characters.
  int unique_chars = 0;

  // Check if there are exactly two unique characters.
  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) {
      unique_chars++;
    }
  }

  // Check if the two unique characters appear exactly twice each.
  if (unique_chars == 2 && count[S[0] - 'A'] == 2 && count[S[1] - 'A'] == 2) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
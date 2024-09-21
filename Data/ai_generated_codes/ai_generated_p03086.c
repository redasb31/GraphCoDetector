#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input string.
  char S[11];

  // Read the input string from the user.
  scanf("%s", S);

  // Initialize a variable to store the length of the longest ACGT substring.
  int maxLength = 0;

  // Iterate through all possible substrings of S.
  for (int i = 0; i < strlen(S); i++) {
    for (int j = i + 1; j <= strlen(S); j++) {
      // Extract the substring from i to j.
      char substring[11];
      strncpy(substring, S + i, j - i);
      substring[j - i] = '\0';

      // Check if the substring is an ACGT string.
      int isACGT = 1;
      for (int k = 0; k < strlen(substring); k++) {
        if (substring[k] != 'A' && substring[k] != 'C' && substring[k] != 'G' && substring[k] != 'T') {
          isACGT = 0;
          break;
        }
      }

      // If the substring is an ACGT string, update the maximum length.
      if (isACGT && strlen(substring) > maxLength) {
        maxLength = strlen(substring);
      }
    }
  }

  // Print the length of the longest ACGT substring.
  printf("%d\n", maxLength);

  return 0;
}
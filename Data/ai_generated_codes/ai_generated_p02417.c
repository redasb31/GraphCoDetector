#include <stdio.h>
#include <ctype.h>

int main() {
  // Initialize an array to store the count of each letter
  int count[26] = {0}; 
  char ch;

  // Read input character by character
  while ((ch = getchar()) != EOF) {
    // Convert to lowercase for case-insensitive counting
    ch = tolower(ch);

    // Check if the character is an alphabet
    if (isalpha(ch)) {
      // Increment the count of the corresponding letter
      count[ch - 'a']++; 
    }
  }

  // Print the count of each letter
  for (int i = 0; i < 26; i++) {
    printf("%c : %d\n", 'a' + i, count[i]); 
  }

  return 0;
}
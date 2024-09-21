#include <stdio.h>
#include <string.h>

int main() {
  char text[81]; // Store input text
  int shift;  // Store the shift value
  
  while (fgets(text, 81, stdin) != NULL) {
    // Find the shift value
    for (shift = 1; shift < 26; shift++) {
      // Check for "the", "this", or "that" in decoded text
      if (strstr(decode(text, shift), "the") != NULL ||
          strstr(decode(text, shift), "this") != NULL ||
          strstr(decode(text, shift), "that") != NULL) {
        break; // Found the shift, exit loop
      }
    }

    // Print the decoded text
    printf("%s", decode(text, shift));
  }
  return 0;
}

// Decodes a text using Caesar cipher with the given shift
char *decode(char *text, int shift) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      // Decode lowercase letters
      text[i] = (text[i] - shift - 'a' + 26) % 26 + 'a';
    }
  }
  return text;
}
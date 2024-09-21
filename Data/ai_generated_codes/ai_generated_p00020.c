#include <stdio.h>

int main() {
  // Declare a character array to store the input text.
  char text[201];

  // Get the input text from the user.
  scanf("%s", text);

  // Iterate through each character in the text.
  for (int i = 0; text[i] != '\0'; i++) {
    // Check if the current character is a lowercase letter.
    if (text[i] >= 'a' && text[i] <= 'z') {
      // Convert the lowercase letter to uppercase.
      text[i] = text[i] - 32; // Subtract 32 from the ASCII value of the lowercase letter to get the uppercase letter.
    }
  }

  // Print the converted text.
  printf("%s\n", text);

  return 0;
}
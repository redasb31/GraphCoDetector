#include <stdio.h>

int main() {
  char str[1200]; // Declare a character array to store the input string
  scanf("%[^\n]", str); // Read the input string from the user
  
  for (int i = 0; str[i] != '\0'; i++) { // Iterate through each character of the string
    if (str[i] >= 'A' && str[i] <= 'Z') { // If the character is uppercase
      str[i] = str[i] + 32; // Convert it to lowercase
    } else if (str[i] >= 'a' && str[i] <= 'z') { // If the character is lowercase
      str[i] = str[i] - 32; // Convert it to uppercase
    }
  }
  printf("%s\n", str); // Print the modified string
  return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
  char s[101]; // Array to store the input string
  int count = 0; // Variable to store the count of matching parentheses pairs surrounding the star
  int i, j; // Loop counters

  // Read the input string
  scanf("%s", s);

  // Find the index of the star symbol
  int star_index = -1;
  for (i = 0; i < strlen(s); i++) {
    if (s[i] == '*') {
      star_index = i;
      break;
    }
  }

  // If the star symbol is not found, the count is 0
  if (star_index == -1) {
    printf("0\n");
    return 0;
  }

  // Iterate through the string from the beginning to the star symbol
  for (i = 0; i < star_index; i++) {
    // If the current character is '('
    if (s[i] == '(') {
      // Search for the matching ')'
      for (j = i + 1; j < star_index; j++) {
        if (s[j] == ')') {
          // If the ')' is found, increment the count
          count++;
          // Break the inner loop
          break;
        }
      }
    }
  }

  // Iterate through the string from the star symbol to the end
  for (i = star_index + 1; i < strlen(s); i++) {
    // If the current character is ')'
    if (s[i] == ')') {
      // Search for the matching '('
      for (j = i - 1; j > star_index; j--) {
        if (s[j] == '(') {
          // If the '(' is found, increment the count
          count++;
          // Break the inner loop
          break;
        }
      }
    }
  }

  // Print the count of matching parentheses pairs surrounding the star
  printf("%d\n", count);

  return 0;
}
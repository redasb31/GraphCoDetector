#include <stdio.h>
#include <string.h>

int main() {
  int n, i, j;
  char str[501][11]; // Array to store strings, 500 strings max, 10 characters per string

  while (1) {
    scanf("%d", &n); // Read the number of strings

    if (n == 0) { // Check for the end of the input
      break;
    }

    // Read all the strings
    for (i = 0; i < n; i++) {
      scanf("%s", str[i]); 
    }

    // Check for lexicographical order
    int isLexicographical = 1; 
    for (i = 0; i < n - 1; i++) {
      // Compare string i with string i+1
      for (j = 0; str[i][j] != '\0' && str[i + 1][j] != '\0'; j++) {
        if (str[i][j] > str[i + 1][j]) { // If current character is greater, it's not lexicographical
          isLexicographical = 0; 
          break; // No need to continue comparison for this pair
        } else if (str[i][j] < str[i + 1][j]) { // If current character is smaller, move to the next pair
          break;
        }
      }
      // If a string is a prefix of the other, it's lexicographically ordered
      if (str[i][j] != '\0' && str[i + 1][j] == '\0' && isLexicographical) {
        isLexicographical = 1;
      } else if (str[i][j] == '\0' && str[i + 1][j] != '\0' && isLexicographical) {
        isLexicographical = 0; // String i is a prefix of string i+1, not lexicographical
      }
      if (isLexicographical == 0) {
        break; // No need to continue further if not lexicographical
      }
    }

    // Print the result
    if (isLexicographical) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}
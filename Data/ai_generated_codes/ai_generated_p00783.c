#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str, int start, int end) {
  while (start < end) {
    if (toupper(str[start]) != toupper(str[end])) {
      return 0;
    }
    start++;
    end--;
  }
  return 1;
}

// Function to find and print palindromes in a string
void findPalindromes(char *str) {
  int len = strlen(str);
  int i, j;
  int palindromeFound = 0;

  // Iterate over all possible palindrome lengths
  for (i = len; i >= 3; i--) {
    // Iterate over all possible starting positions for a palindrome of length i
    for (j = 0; j <= len - i; j++) {
      // Check if the substring is a palindrome
      if (isPalindrome(str, j, j + i - 1)) {
        // Print the palindrome in uppercase
        printf("%.*s ", i, &str[j]);
        palindromeFound = 1;
      }
    }
  }

  // If no palindromes were found, print an empty line
  if (!palindromeFound) {
    printf("\n");
  } else {
    printf("\n");
  }
}

int main() {
  char line[1024];

  // Read input lines until EOF
  while (fgets(line, sizeof(line), stdin) != NULL) {
    // Remove trailing newline character
    line[strcspn(line, "\n")] = 0;

    // Find and print palindromes in the line
    findPalindromes(line);
  }

  return 0;
}
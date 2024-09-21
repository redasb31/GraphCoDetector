#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to generate all possible palindromes
void generatePalindromes(char *str, int len, char *current, int index, int *count, long long k) {
  if (index == len) {
    // Check if the generated string is a palindrome
    if (isPalindrome(current)) {
      (*count)++;
      if (*count == k) {
        printf("%s\n", current);
        return;
      }
    }
    return;
  }
  // Add the current character to both ends of the string
  current[index] = str[index];
  current[len - index - 1] = str[index];
  // Recursively generate palindromes
  generatePalindromes(str, len, current, index + 1, count, k);
}

int main() {
  char str[2001];
  long long k;
  scanf("%s\n%lld", str, &k);
  int len = strlen(str);
  // Allocate memory for the palindrome string
  char *palindrome = malloc((len * 2 + 1) * sizeof(char));
  if (palindrome == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  // Initialize the palindrome string
  memset(palindrome, '\0', (len * 2 + 1) * sizeof(char));
  // Count the number of palindromes
  int count = 0;
  // Generate all possible palindromes
  generatePalindromes(str, len, palindrome, 0, &count, k);
  // If the number of palindromes is less than k
  if (count < k) {
    printf("NONE\n");
  }
  free(palindrome);
  return 0;
}
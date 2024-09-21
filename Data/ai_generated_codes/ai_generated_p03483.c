#include <stdio.h>
#include <string.h>

// Function to determine if a string can be turned into a palindrome
// by swapping adjacent characters.
// Returns the minimum number of swaps required, or -1 if it's impossible.
int can_be_palindrome(char *s) {
  int n = strlen(s);
  int count = 0;

  // Iterate over the string, comparing characters from both ends
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    // If characters don't match, increment count and move pointers inward
    if (s[i] != s[j]) {
      count++;
      // If pointers are adjacent, we can't make a palindrome
      if (i + 1 == j) {
        return -1;
      }
    }
  }

  // Return the number of swaps needed
  return count;
}

int main() {
  char s[200001];

  // Read the string from input
  scanf("%s", s);

  // Print the minimum number of swaps or -1 if impossible
  printf("%d\n", can_be_palindrome(s));

  return 0;
}
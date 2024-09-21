#include <stdio.h>
#include <string.h>

// Function to check if a string is well-formed in the ICPC language
int is_well_formed(char *s) {
  int stack_size = 0; // Initialize stack size to 0
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(') { // If character is opening parenthesis, increment stack size
      stack_size++;
    } else if (s[i] == ')') { // If character is closing parenthesis
      if (stack_size == 0) { // If stack is empty, it's not well-formed
        return 0;
      }
      stack_size--; // Decrement stack size
    }
  }
  return stack_size == 0; // Check if the stack is empty after processing all characters
}

int main() {
  int q; // Number of queries
  scanf("%d", &q);
  char s[1000000] = ""; // Initialize empty string s
  int p, n; // Position and number of characters to insert
  char c; // Character to insert
  for (int i = 0; i < q; i++) {
    scanf("%d %c %d", &p, &c, &n); // Read query input
    // Insert the character n times at position p in the string
    for (int j = 0; j < n; j++) {
      memmove(s + p + j + 1, s + p + j, strlen(s) - p - j + 1); // Shift characters to make space for the new character
      s[p + j] = c; // Insert the character at position p + j
    }
    // Check if the string is well-formed and print the output
    if (is_well_formed(s)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
#include <stdio.h>
#include <string.h>

// Function to check if two strings are isomorphic
int is_isomorphic(char *s, char *t) {
  // Check if the lengths are equal
  if (strlen(s) != strlen(t)) {
    return 0;
  }

  // Create a mapping array to store the mapping between characters
  int mapping[26];
  memset(mapping, -1, sizeof(mapping));

  // Iterate over the strings
  for (int i = 0; s[i] != '\0'; i++) {
    // If the character in s has not been mapped yet
    if (mapping[s[i] - 'a'] == -1) {
      // Map the character in s to the character in t
      mapping[s[i] - 'a'] = t[i];
    } else {
      // If the character in s is already mapped and the mapping does not match the current character in t
      if (mapping[s[i] - 'a'] != t[i]) {
        return 0;
      }
    }
  }

  // If all characters are mapped correctly, the strings are isomorphic
  return 1;
}

// Function to generate all strings of length n in normal form
void generate_normal_form_strings(int n, char *str, int index) {
  // Base case: if the string is complete, print it
  if (index == n) {
    printf("%s\n", str);
    return;
  }

  // Iterate over all lowercase letters
  for (char c = 'a'; c <= 'z'; c++) {
    // Check if the current letter is valid (not repeated in the current string)
    int valid = 1;
    for (int i = 0; i < index; i++) {
      if (str[i] == c) {
        valid = 0;
        break;
      }
    }

    // If the letter is valid, add it to the string and recursively generate the remaining part
    if (valid) {
      str[index] = c;
      generate_normal_form_strings(n, str, index + 1);
    }
  }
}

int main() {
  int n;

  // Read the length of the string
  scanf("%d", &n);

  // Create a string of length n
  char str[n + 1];
  str[n] = '\0';

  // Generate all strings in normal form
  generate_normal_form_strings(n, str, 0);

  return 0;
}
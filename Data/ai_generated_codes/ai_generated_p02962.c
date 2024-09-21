#include <stdio.h>
#include <string.h>

// Function to check if a string is a substring of another string
int is_substring(char *s, char *t) {
  int s_len = strlen(s);
  int t_len = strlen(t);

  // If the length of t is greater than the length of s, it cannot be a substring
  if (t_len > s_len) {
    return 0;
  }

  // Iterate through all possible starting positions of t in s
  for (int i = 0; i <= s_len - t_len; i++) {
    // Check if the substring matches at this position
    int j;
    for (j = 0; j < t_len; j++) {
      if (s[i + j] != t[j]) {
        break;
      }
    }
    // If the entire substring matches, return 1
    if (j == t_len) {
      return 1;
    }
  }
  // If no match is found, return 0
  return 0;
}

// Function to find the maximum number of copies of t that are a substring of s
int find_max_copies(char *s, char *t) {
  int s_len = strlen(s);
  int t_len = strlen(t);

  // If the length of t is greater than the length of s, it cannot be a substring
  if (t_len > s_len) {
    return 0;
  }

  // If t is the empty string, any number of copies is a substring
  if (t_len == 0) {
    return -1;
  }

  // Initialize the maximum number of copies to 0
  int max_copies = 0;

  // Iterate through all possible numbers of copies of t
  for (int i = 1; i <= (s_len / t_len) + 1; i++) {
    // Create a string that represents the concatenation of i copies of t
    char *t_copies = malloc((i * t_len + 1) * sizeof(char));
    for (int j = 0; j < i; j++) {
      strcpy(t_copies + (j * t_len), t);
    }
    t_copies[i * t_len] = '\0';

    // Check if the concatenation of i copies of t is a substring of s
    if (is_substring(s, t_copies)) {
      // Update the maximum number of copies
      max_copies = i;
    }
    // Free the dynamically allocated memory
    free(t_copies);
  }

  // If the maximum number of copies is 0, it means no copies are substrings
  if (max_copies == 0) {
    return 0;
  }

  // Otherwise, return the maximum number of copies
  return max_copies;
}

int main() {
  // Read the input strings from standard input
  char s[500001];
  char t[500001];
  scanf("%s", s);
  scanf("%s", t);

  // Find the maximum number of copies of t that are a substring of s
  int max_copies = find_max_copies(s, t);

  // Print the output to standard output
  printf("%d\n", max_copies);

  return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
  char s[101]; // String s
  char p[101]; // Pattern p

  // Read the input string s
  scanf("%s", s);
  // Read the input pattern p
  scanf("%s", p);

  int s_len = strlen(s);
  int p_len = strlen(p);

  // Create a new string by concatenating s with itself
  char new_s[201];
  strcpy(new_s, s);
  strcat(new_s, s);

  // Check if the pattern p is present in the new string
  int found = 0;
  for (int i = 0; i <= s_len; i++) {
    if (strncmp(new_s + i, p, p_len) == 0) {
      found = 1;
      break;
    }
  }

  // Print the result
  if (found) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
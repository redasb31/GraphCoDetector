#include <stdio.h>
#include <string.h>

// Function to check if two programs are identical
int are_identical(char *s1, char *s2) {
  return strcmp(s1, s2) == 0;
}

// Function to check if two programs are close (differ only by one string literal)
int are_close(char *s1, char *s2) {
  int i, j, quote_count1 = 0, quote_count2 = 0;
  int diff_count = 0;
  for (i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++) {
    if (s1[i] == '"' && s2[j] == '"') {
      quote_count1++;
      quote_count2++;
      if (quote_count1 % 2 == 0 && quote_count2 % 2 == 0) {
        // Inside a string literal
        while (s1[i] != '"' && s2[j] != '"') {
          if (s1[i] != s2[j]) {
            diff_count++;
          }
          i++;
          j++;
        }
      }
    } else if (s1[i] != s2[j]) {
      diff_count++;
    }
  }
  return diff_count == 1;
}

int main() {
  char s1[201], s2[201];

  while (1) {
    // Read input programs
    if (scanf("%s\n%s\n", s1, s2) == EOF) {
      break;
    }

    // Check if the programs are identical, close, or different
    if (are_identical(s1, s2)) {
      printf("IDENTICAL\n");
    } else if (are_close(s1, s2)) {
      printf("CLOSE\n");
    } else {
      printf("DIFFERENT\n");
    }
  }

  return 0;
}
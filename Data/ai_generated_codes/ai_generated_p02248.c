#include <stdio.h>
#include <string.h>

int main() {
  char text[1000001]; // Maximum length of text
  char pattern[10001]; // Maximum length of pattern

  // Read the input text and pattern
  scanf("%s", text);
  scanf("%s", pattern);

  int textLen = strlen(text);
  int patternLen = strlen(pattern);

  // Iterate through the text to find the pattern
  for (int i = 0; i <= textLen - patternLen; i++) {
    // Check if the current substring of text matches the pattern
    int j;
    for (j = 0; j < patternLen; j++) {
      if (text[i + j] != pattern[j]) {
        break;
      }
    }

    // If the entire pattern is matched, print the index
    if (j == patternLen) {
      printf("%d\n", i);
    }
  }

  return 0;
}
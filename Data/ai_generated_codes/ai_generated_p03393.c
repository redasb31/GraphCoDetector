#include <stdio.h>
#include <string.h>

int main() {
  char S[27]; // Maximum length of the word is 26

  // Input the word
  scanf("%s", S);

  // Find the position of the last character that can be incremented
  int i = strlen(S) - 1;
  while (i >= 0 && S[i] == 'z') {
    i--;
  }

  // If we reached the beginning of the word and the last character is 'z', there is no next word
  if (i == -1) {
    printf("-1\n");
    return 0;
  }

  // Increment the last character that can be incremented
  S[i]++;

  // Fill the remaining characters with the next available letters in alphabetical order
  for (int j = i + 1; j < strlen(S); j++) {
    S[j] = 'a' + j - i - 1;
  }

  // Print the next word
  printf("%s\n", S);

  return 0;
}
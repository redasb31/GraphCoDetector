#include <stdio.h>
#include <string.h>

int main() {
  char S[51];
  scanf("%s", S);

  // Check if the string has the correct characters
  int correct_chars = 0;
  for (int i = 0; i < strlen(S); i++) {
    if (S[i] == 'A' || S[i] == 'K' || S[i] == 'I' || S[i] == 'H' || S[i] == 'B' || S[i] == 'R') {
      correct_chars++;
    }
  }

  // Check if the string has all the required characters
  if (correct_chars != 8) {
    printf("NO\n");
    return 0;
  }

  // Check if the characters are in the correct order
  int i = 0, j = 0;
  while (S[i] != '\0' && j < 9) {
    if (S[i] == 'A' && j == 0) {
      j++;
    } else if (S[i] == 'K' && j == 1) {
      j++;
    } else if (S[i] == 'I' && j == 2) {
      j++;
    } else if (S[i] == 'H' && j == 3) {
      j++;
    } else if (S[i] == 'A' && j == 4) {
      j++;
    } else if (S[i] == 'B' && j == 5) {
      j++;
    } else if (S[i] == 'A' && j == 6) {
      j++;
    } else if (S[i] == 'R' && j == 7) {
      j++;
    } else if (S[i] == 'A' && j == 8) {
      j++;
    }
    i++;
  }

  // If all characters are in the correct order, print YES
  if (j == 9) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
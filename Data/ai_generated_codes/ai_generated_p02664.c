#include <stdio.h>
#include <string.h>

int main() {
  char T[200001]; // Maximum length of the input string
  scanf("%s", T);

  int len = strlen(T); // Length of the input string

  // Iterate through the string and replace '?' with either 'P' or 'D' to maximize the count
  for (int i = 0; i < len; i++) {
    if (T[i] == '?') {
      // If the previous character is 'D', replace '?' with 'P' to form 'DP'
      if (i > 0 && T[i - 1] == 'D') {
        T[i] = 'P';
      } else {
        // Otherwise, replace '?' with 'D' to maximize the number of 'D's
        T[i] = 'D';
      }
    }
  }

  printf("%s\n", T); // Print the modified string with the maximum doctoral and postdoctoral quotient

  return 0;
}
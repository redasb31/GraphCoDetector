#include <stdio.h>
#include <string.h>

int main() {
  int n, i, j, k, l, count;
  char words[40][11];

  // Loop for multiple datasets
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    // Read words into a 2D array
    for (i = 0; i < n; i++) {
      scanf("%s", words[i]);
    }

    // Loop to find the Short Phrase
    for (i = 0; i < n - 8; i++) {
      // Check if the current word is the start of a Short Phrase
      if (strlen(words[i]) + strlen(words[i + 1]) == 5 &&
          strlen(words[i + 2]) + strlen(words[i + 3]) == 7 &&
          strlen(words[i + 4]) == 5 &&
          strlen(words[i + 5]) + strlen(words[i + 6]) == 7 &&
          strlen(words[i + 7]) + strlen(words[i + 8]) == 7) {
        printf("%d\n", i + 1); // Output the index (starting from 1)
        break;
      }
    }
  }

  return 0;
}
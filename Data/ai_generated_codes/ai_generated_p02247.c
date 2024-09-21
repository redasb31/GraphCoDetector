#include <stdio.h>
#include <string.h>

int main() {
  char T[1001]; // Text string
  char P[1001]; // Pattern string

  // Input the text string
  scanf("%s", T);

  // Input the pattern string
  scanf("%s", P);

  int lenT = strlen(T); // Length of the text string
  int lenP = strlen(P); // Length of the pattern string

  // Loop through the text string
  for (int i = 0; i <= lenT - lenP; i++) {
    // Check if the current substring of T matches P
    int match = 1;
    for (int j = 0; j < lenP; j++) {
      if (T[i + j] != P[j]) {
        match = 0;
        break;
      }
    }

    // If a match is found, print the index
    if (match) {
      printf("%d\n", i);
    }
  }

  return 0;
}
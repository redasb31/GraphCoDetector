#include <stdio.h>

int main() {
  int N; // Number of arare in the bag
  char S[101]; // Array to store the colors of the arare

  // Read the number of arare
  scanf("%d", &N);

  // Read the colors of the arare
  for (int i = 0; i < N; i++) {
    scanf(" %c", &S[i]);
  }

  // Check if the bag contains four colors (pink, white, green, and yellow)
  int hasYellow = 0; // Flag to check if yellow arare is present
  for (int i = 0; i < N; i++) {
    if (S[i] == 'Y') {
      hasYellow = 1;
      break; // No need to continue if yellow arare is found
    }
  }

  // If yellow arare is found, print "Four"
  if (hasYellow) {
    printf("Four\n");
  } else {
    // Otherwise, print "Three"
    printf("Three\n");
  }

  return 0;
}
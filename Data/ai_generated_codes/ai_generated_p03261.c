#include <stdio.h>
#include <string.h>

int main() {
  // N: the number of words announced
  int N;
  scanf("%d", &N);

  // W: array to store the words announced
  char W[100][11]; // 100 words, each with a maximum length of 10 characters

  // Read the words from the input
  for (int i = 0; i < N; i++) {
    scanf("%s", W[i]);
  }

  // Flag to indicate if the rules were followed
  int valid = 1; // Assume valid initially

  // Check if the rules were followed for each word
  for (int i = 1; i < N; i++) {
    // Check if the last character of the previous word matches the first character of the current word
    if (W[i - 1][strlen(W[i - 1]) - 1] != W[i][0]) {
      valid = 0; // Rules not followed, set the flag to 0
      break; // Stop checking further words as the rules are already broken
    }
  }

  // Output the result
  if (valid) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables to store the input values
  int K;
  char S[101];

  // Read the input values from the standard input
  scanf("%d\n", &K); // Read the value of K
  fgets(S, 101, stdin); // Read the string S, including the newline character

  // Remove the newline character from the string S
  S[strcspn(S, "\n")] = 0; 

  // Check if the length of S is greater than K
  if (strlen(S) > K) {
    // If the length of S is greater than K, truncate S to K characters and append "..."
    S[K] = '\0'; // Truncate S to K characters
    strcat(S, "..."); // Append "..." to the truncated string
  }

  // Print the modified string S
  printf("%s\n", S);

  return 0;
}
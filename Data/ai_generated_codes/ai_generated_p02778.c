#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable to store the input string
  char S[101];

  // Read the input string from standard input
  scanf("%s", S);

  // Iterate through each character in the input string
  for (int i = 0; i < strlen(S); i++) {
    // Replace each character with 'x'
    S[i] = 'x';
  }

  // Print the modified string
  printf("%s\n", S);

  return 0;
}
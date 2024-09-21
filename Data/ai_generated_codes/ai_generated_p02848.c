#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables for the shift value and the string.
  int N;
  char S[10001];

  // Read the shift value and the string from standard input.
  scanf("%d\n", &N);
  scanf("%s", S);

  // Iterate over each character in the string.
  for (int i = 0; i < strlen(S); i++) {
    // Calculate the shifted character index.
    int shiftedIndex = (S[i] - 'A' + N) % 26;

    // Convert the shifted index back to a character.
    S[i] = 'A' + shiftedIndex;
  }

  // Print the shifted string.
  printf("%s\n", S);

  return 0;
}
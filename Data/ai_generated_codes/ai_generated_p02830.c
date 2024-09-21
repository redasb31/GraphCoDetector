#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables to store the length of the strings and the strings themselves
  int N;
  char S[101], T[101];

  // Read the length of the strings
  scanf("%d", &N);

  // Read the strings S and T
  scanf("%s %s", S, T);

  // Iterate through the strings and print the alternating characters
  for (int i = 0; i < N; i++) {
    printf("%c%c", S[i], T[i]);
  }

  // Print a newline character at the end
  printf("\n");

  return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables to store the strings
  char S[101];
  char T[101];

  // Read the strings from the standard input
  scanf("%s %s", S, T);

  // Concatenate the strings in the desired order
  printf("%s%s\n", T, S);

  return 0;
}
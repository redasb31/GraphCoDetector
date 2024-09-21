#include <stdio.h>
#include <string.h>

int main() {
  char S[101];
  scanf("%s", S);

  int len = strlen(S);
  int hugs = 0;

  // Iterate over half the string
  for (int i = 0; i < len / 2; i++) {
    // If the characters at the start and end don't match
    if (S[i] != S[len - i - 1]) {
      // Increment the hug count
      hugs++;
    }
  }

  // Print the minimum number of hugs
  printf("%d\n", hugs);

  return 0;
}
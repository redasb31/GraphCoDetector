#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables for the input strings
  char S[11]; // Maximum length of S is 10
  char T[12]; // Maximum length of T is 11

  // Read the input strings
  scanf("%s", S);
  scanf("%s", T);

  // Check if the length of T is one greater than the length of S
  if (strlen(T) != strlen(S) + 1) {
    printf("No\n");
    return 0;
  }

  // Check if the first |S| characters of T are the same as S
  for (int i = 0; i < strlen(S); i++) {
    if (S[i] != T[i]) {
      printf("No\n");
      return 0;
    }
  }

  // If all checks pass, T satisfies the property
  printf("Yes\n");

  return 0;
}
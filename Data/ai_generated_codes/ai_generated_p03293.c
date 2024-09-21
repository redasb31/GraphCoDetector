#include <stdio.h>
#include <string.h>

int main() {
  char S[101], T[101];

  // Read input strings
  scanf("%s", S);
  scanf("%s", T);

  // Check if the lengths of the strings are equal
  if (strlen(S) != strlen(T)) {
    printf("No\n");
    return 0;
  }

  // Concatenate S with itself
  char S2[202];
  strcpy(S2, S);
  strcat(S2, S);

  // Check if T is a substring of S2
  if (strstr(S2, T) != NULL) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
  char S[101]; // Maximum length of the input string

  // Read the input string
  scanf("%s", S);

  // Check if the string is already "keyence"
  if (strcmp(S, "keyence") == 0) {
    printf("YES\n");
    return 0;
  }

  // Check if the string can be made "keyence" by removing a substring
  int len = strlen(S);
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j <= len; j++) {
      // Create a temporary string by removing the substring from i to j-1
      char temp[101];
      int k = 0;
      for (int l = 0; l < i; l++) {
        temp[k++] = S[l];
      }
      for (int l = j; l < len; l++) {
        temp[k++] = S[l];
      }
      temp[k] = '\0';

      // Check if the temporary string is "keyence"
      if (strcmp(temp, "keyence") == 0) {
        printf("YES\n");
        return 0;
      }
    }
  }

  // If no substring removal results in "keyence", it's not a KEYENCE string
  printf("NO\n");
  return 0;
}
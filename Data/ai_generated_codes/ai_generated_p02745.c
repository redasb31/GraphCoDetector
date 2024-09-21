#include <stdio.h>
#include <string.h>

// Function to check if a string is a substring of another string
int isSubstring(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  for (int i = 0; i <= len2 - len1; i++) {
    int j;
    for (j = 0; j < len1; j++) {
      if (str1[j] != '?' && str2[i + j] != '?' && str1[j] != str2[i + j]) {
        break;
      }
    }
    if (j == len1) {
      return 1;
    }
  }
  return 0;
}

int main() {
  char a[2001], b[2001], c[2001];

  // Input the strings a, b, and c
  scanf("%s", a);
  scanf("%s", b);
  scanf("%s", c);

  // Find the minimum length of s by checking if each string is a substring of the other two
  int minLen = 2000;
  if (isSubstring(a, b) && isSubstring(a, c)) {
    minLen = strlen(a);
  }
  if (isSubstring(b, a) && isSubstring(b, c)) {
    minLen = strlen(b);
  }
  if (isSubstring(c, a) && isSubstring(c, b)) {
    minLen = strlen(c);
  }

  // Output the minimum length of s
  printf("%d\n", minLen);

  return 0;
}
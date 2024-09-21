#include <stdio.h>
#include <string.h>

int main() {
  char s[101], t[101];
  // Read input strings
  scanf("%s", s);
  scanf("%s", t);

  // Sort the strings lexicographically
  qsort(s, strlen(s), sizeof(char), (int(*)(const void *, const void *))strcmp);
  qsort(t, strlen(t), sizeof(char), (int(*)(const void *, const void *))strcmp);

  // Compare the strings for lexicographic order
  if (strcmp(s, t) < 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
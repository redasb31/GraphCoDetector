#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char s[100005];
  scanf("%s", s);
  int n = strlen(s);

  // If the last character is '1', it's impossible to have a tree that satisfies the conditions.
  if (s[n - 1] == '1') {
    printf("-1\n");
    return 0;
  }

  // Construct a tree that satisfies the conditions.
  // The tree will be a chain with the first node connected to all other nodes.
  for (int i = 1; i < n; i++) {
    printf("%d %d\n", 1, i + 1);
  }

  return 0;
}
#include <stdio.h>
#include <string.h>

#define MAXN 200000
#define MAXS 1000000

char s[MAXN][MAXS + 1];

int main() {
  int n;
  scanf("%d", &n);

  // Read the strings
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }

  // Count the number of good pairs
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // Check if Limak can obtain one string from the other
      if (canObtain(s[i], s[j]) || canObtain(s[j], s[i])) {
        count++;
      }
    }
  }

  printf("%d\n", count);
  return 0;
}

// Check if Limak can obtain string b from string a
int canObtain(char *a, char *b) {
  int la = strlen(a);
  int lb = strlen(b);

  // If the lengths are not compatible, Limak cannot obtain b from a
  if (la < lb) {
    return 0;
  }

  // Iterate over the characters of b
  int i = 0;
  int j = 0;
  while (i < lb) {
    // If the characters match, move to the next character of b
    if (a[j] == b[i]) {
      i++;
      j++;
    }
    // Otherwise, skip the current character of a
    else {
      j++;
    }

    // If we reach the end of a, Limak cannot obtain b from a
    if (j >= la) {
      return 0;
    }
  }

  // If we reach this point, Limak can obtain b from a
  return 1;
}
#include <stdio.h>
#include <string.h>

int main() {
  char s[200005];
  char t[200005];

  // Input the strings S and T
  scanf("%s", s);
  scanf("%s", t);

  // Calculate the length of the strings
  int n = strlen(s);

  // Initialize a counter for the number of operations
  int operations = 0;

  // Iterate through each character of the strings
  for (int i = 0; i < n; i++) {
    // If the characters at the current index are different, increment the counter
    if (s[i] != t[i]) {
      operations++;
    }
  }

  // Print the minimum number of operations required
  printf("%d\n", operations);

  return 0;
}
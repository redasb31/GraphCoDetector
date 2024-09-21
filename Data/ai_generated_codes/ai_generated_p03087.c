#include <stdio.h>
#include <string.h>

int main() {
  // Input the length of the string and the number of queries
  int n, q;
  scanf("%d %d", &n, &q);

  // Input the string
  char s[100005];
  scanf("%s", s);

  // Loop through each query
  for (int i = 0; i < q; i++) {
    // Input the start and end indices for the current query
    int l, r;
    scanf("%d %d", &l, &r);

    // Initialize the count of "AC" occurrences to 0
    int count = 0;

    // Loop through the substring defined by the current query
    for (int j = l; j < r - 1; j++) {
      // Check if the current character and the next character form "AC"
      if (s[j] == 'A' && s[j + 1] == 'C') {
        // Increment the count if "AC" is found
        count++;
      }
    }

    // Print the count of "AC" occurrences for the current query
    printf("%d\n", count);
  }

  return 0;
}
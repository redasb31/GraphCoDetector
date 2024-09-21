#include <stdio.h>
#include <string.h>

int main() {
  int n;
  char s[4001];

  scanf("%d", &n);
  scanf("%s", s);

  long long count = 0; // Use long long for potential large counts

  // Iterate over all possible starting positions for the triplet
  for (int i = 0; i < n - 2; i++) {
    // Iterate over all possible middle positions for the triplet
    for (int j = i + 1; j < n - 1; j++) {
      // Iterate over all possible end positions for the triplet
      for (int k = j + 1; k < n; k++) {
        // Check if the triplet satisfies the first condition
        if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) {
          // Check if the triplet satisfies the second condition
          if (j - i != k - j) {
            // If both conditions are satisfied, increment the count
            count++;
          }
        }
      }
    }
  }

  printf("%lld\n", count);

  return 0;
}
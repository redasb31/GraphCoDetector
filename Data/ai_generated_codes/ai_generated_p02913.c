#include <stdio.h>
#include <string.h>

int main() {
  // Get the length of the string
  int N;
  scanf("%d", &N);

  // Get the string
  char S[5001];
  scanf("%s", S);

  // Initialize the maximum length to 0
  int max_len = 0;

  // Iterate over all possible lengths
  for (int len = 1; len <= N; len++) {
    // Iterate over all possible starting positions of the first occurrence
    for (int l1 = 1; l1 <= N - len + 1; l1++) {
      // Iterate over all possible starting positions of the second occurrence
      for (int l2 = l1 + len; l2 <= N - len + 1; l2++) {
        // Check if the two substrings are equal
        int i;
        for (i = 0; i < len; i++) {
          if (S[l1 + i] != S[l2 + i]) {
            break;
          }
        }
        // If the two substrings are equal, update the maximum length
        if (i == len) {
          max_len = len;
        }
      }
    }
  }

  // Print the maximum length
  printf("%d\n", max_len);

  return 0;
}
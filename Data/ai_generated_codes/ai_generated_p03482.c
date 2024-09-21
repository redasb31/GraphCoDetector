#include <stdio.h>
#include <string.h>

int main() {
  char S[100005];
  scanf("%s", S);

  // Length of the string
  int N = strlen(S);

  // Initialize the maximum K to 1
  int K = 1;

  // Iterate over all possible lengths of K
  for (int k = 1; k <= N; k++) {
    // Flag to check if all characters can be turned to 0
    int all_zero = 1;

    // Iterate over the string in steps of K
    for (int i = 0; i < N; i += k) {
      // Check if a segment of length K can be found where all characters are 1
      int segment_all_one = 1;
      for (int j = i; j < i + k && j < N; j++) {
        if (S[j] == '0') {
          segment_all_one = 0;
          break;
        }
      }

      // If a segment of length K with all characters 1 is found, then we cannot turn all characters to 0
      if (segment_all_one) {
        all_zero = 0;
        break;
      }
    }

    // If all characters can be turned to 0 with K, update the maximum K
    if (all_zero) {
      K = k;
    }
  }

  printf("%d\n", K);

  return 0;
}
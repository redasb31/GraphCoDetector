#include <stdio.h>

int main() {
  // Declare variables for the sizes of the sequences and the number of matches
  int n, q, c = 0;

  // Read the size of the first sequence (n)
  scanf("%d", &n);

  // Declare an array to store the first sequence (S)
  int S[n];

  // Read the elements of the first sequence (S)
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  // Read the size of the second sequence (q)
  scanf("%d", &q);

  // Declare an array to store the second sequence (T)
  int T[q];

  // Read the elements of the second sequence (T)
  for (int i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }

  // Iterate through the second sequence (T)
  for (int i = 0; i < q; i++) {
    // Iterate through the first sequence (S)
    for (int j = 0; j < n; j++) {
      // If an element in T is found in S, increment the match count (c)
      if (T[i] == S[j]) {
        c++;
        // Break the inner loop since we found a match
        break;
      }
    }
  }

  // Print the number of matches (c)
  printf("%d\n", c);

  return 0;
}
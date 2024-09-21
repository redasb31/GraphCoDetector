#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables
  int N, K;
  char S[11];

  // Read input
  scanf("%d", &N);
  scanf("%s", S);
  scanf("%d", &K);

  // Calculate the K-th character of S
  char target_char = S[K - 1];

  // Replace characters that differ from the K-th character
  for (int i = 0; i < N; i++) {
    if (S[i] != target_char) {
      S[i] = '*';
    }
  }

  // Print the modified string
  printf("%s\n", S);

  return 0;
}
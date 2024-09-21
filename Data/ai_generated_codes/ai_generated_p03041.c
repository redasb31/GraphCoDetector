#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables
  int N, K;
  char S[51];

  // Read input
  scanf("%d %d\n", &N, &K);
  scanf("%s", S);

  // Lowercase the K-th character
  S[K - 1] = tolower(S[K - 1]);

  // Print the modified string
  printf("%s\n", S);

  return 0;
}
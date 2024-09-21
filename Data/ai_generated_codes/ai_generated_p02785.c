#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: number of monsters
  // K: maximum number of special moves
  int N, K;
  scanf("%d %d", &N, &K);

  // H: array of monster healths
  int *H = malloc(sizeof(int) * N);

  // Read monster healths from input
  for (int i = 0; i < N; i++) {
    scanf("%d", &H[i]);
  }

  // Sort the monster healths in descending order
  // (We want to use Special Move on the strongest monsters first)
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (H[i] < H[j]) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
      }
    }
  }

  // Calculate the minimum number of attacks
  long long int attacks = 0;
  for (int i = 0; i < N; i++) {
    // If we have remaining special moves, use one on the current monster
    if (K > 0) {
      K--;
    } else {
      // Otherwise, use attacks to defeat the current monster
      attacks += H[i];
    }
  }

  // Print the result
  printf("%lld\n", attacks);

  free(H);
  return 0;
}
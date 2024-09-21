#include <stdio.h>

int main() {
  // N: number of Snuke Cats
  int N;
  // a_i: xor of all integers except the one on Snuke Cat i's scarf
  int a[200000];

  // Read input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the xor of all integers
  int total_xor = 0;
  for (int i = 0; i < N; i++) {
    total_xor ^= a[i];
  }

  // Calculate the integer on each Snuke Cat's scarf
  for (int i = 0; i < N; i++) {
    // The integer on Snuke Cat i's scarf is the xor of the total xor and a_i
    printf("%d ", total_xor ^ a[i]);
  }

  printf("\n");

  return 0;
}
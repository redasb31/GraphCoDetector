#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
  // N: number of elements in the permutation
  // Q: number of queries
  int N, Q;
  scanf("%d %d", &N, &Q);

  // p: the permutation array
  int *p = malloc(sizeof(int) * (N + 1));
  for (int i = 1; i <= N; i++) {
    p[i] = i;
  }

  // cycle_len: array to store the length of each cycle in the permutation
  int *cycle_len = malloc(sizeof(int) * (N + 1));

  // Calculate the length of each cycle in the initial permutation
  for (int i = 1; i <= N; i++) {
    int j = i, len = 0;
    while (p[j] != i) {
      j = p[j];
      len++;
    }
    cycle_len[i] = len + 1;
  }

  // Process each query
  for (int i = 0; i < Q; i++) {
    // x and y: indices to swap
    int x, y;
    scanf("%d %d", &x, &y);

    // Swap the elements at indices x and y
    int temp = p[x];
    p[x] = p[y];
    p[y] = temp;

    // Update the cycle length after swapping
    if (cycle_len[x] != cycle_len[y]) {
      cycle_len[x] = cycle_len[x] + cycle_len[y];
      cycle_len[y] = cycle_len[x];
    }

    // Calculate the period of the updated permutation
    int period = 1;
    for (int j = 1; j <= N; j++) {
      period = (period * cycle_len[j]) % MOD;
    }

    // Print the period modulo 10^9 + 7
    printf("%d\n", period);
  }

  free(p);
  free(cycle_len);

  return 0;
}
#include <stdio.h>

int main() {
  // N: number of triples
  // K: starting integer
  int N, K;
  scanf("%d %d", &N, &K);

  // Check if it's possible to partition
  // If K is even, we can always partition into triples
  // where a_i = K + 3*i - 3, b_i = K + 3*i - 2, c_i = K + 3*i - 1
  if (K % 2 == 0) {
    // Print the triples
    for (int i = 1; i <= N; i++) {
      printf("%d %d %d\n", K + 3 * i - 3, K + 3 * i - 2, K + 3 * i - 1);
    }
  } else {
    // If K is odd, it's impossible to partition
    printf("-1\n");
  }

  return 0;
}
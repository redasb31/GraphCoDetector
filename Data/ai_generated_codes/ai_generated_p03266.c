#include <stdio.h>

int main() {
  // N: the upper bound for a, b, and c
  int N;
  // K: the divisor for a+b, b+c, and c+a
  int K;

  // Read N and K from the standard input
  scanf("%d %d", &N, &K);

  // Initialize count to 0
  int count = 0;

  // Iterate through all possible values of a, b, and c
  for (int a = 1; a <= N; a++) {
    for (int b = 1; b <= N; b++) {
      for (int c = 1; c <= N; c++) {
        // Check if a+b, b+c, and c+a are all multiples of K
        if (((a + b) % K == 0) && ((b + c) % K == 0) && ((c + a) % K == 0)) {
          // If all conditions are met, increment count
          count++;
        }
      }
    }
  }

  // Print the count of valid triples
  printf("%d\n", count);

  return 0;
}
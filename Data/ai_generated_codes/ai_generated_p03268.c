#include <stdio.h>

int main() {
  // Declare variables for N and K
  int N, K;

  // Read input values for N and K
  scanf("%d %d", &N, &K);

  // Initialize count for valid triples
  int count = 0;

  // Iterate over all possible values for a, b, and c
  for (int a = 1; a <= N; a++) {
    for (int b = 1; b <= N; b++) {
      for (int c = 1; c <= N; c++) {
        // Check if the sums a+b, b+c, and c+a are multiples of K
        if ((a + b) % K == 0 && (b + c) % K == 0 && (c + a) % K == 0) {
          // Increment count if all conditions are met
          count++;
        }
      }
    }
  }

  // Print the total count of valid triples
  printf("%d\n", count);

  return 0;
}
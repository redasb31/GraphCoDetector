#include <stdio.h>

// Define the modulo constant
#define MOD 998244353

int main() {
  // Read input values for N and M
  int N, M;
  scanf("%d %d", &N, &M);

  // Declare arrays to store the input values
  int a[N], b[M];

  // Read input values for the arrays a and b
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &b[i]);
  }

  // Calculate the array c
  int c[N + M - 1];
  for (int i = 0; i < N + M - 1; i++) {
    c[i] = 0;
    // Calculate the sum of products using modular arithmetic
    for (int j = 0; j <= i && j < N && i - j < M; j++) {
      c[i] = (c[i] + (long long)a[j] * b[i - j]) % MOD; // Use long long to avoid overflow
    }
  }

  // Print the calculated array c
  for (int i = 0; i < N + M - 1; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");

  return 0;
}
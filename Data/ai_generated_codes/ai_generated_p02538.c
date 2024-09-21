#include <stdio.h>
#include <string.h>

#define MOD 998244353

int main() {
  // N: length of the string
  // Q: number of queries
  int N, Q;
  scanf("%d %d", &N, &Q);

  // S: the string, initialized with all '1's
  char S[200001];
  memset(S, '1', sizeof(S));
  S[N] = '\0'; // Add null terminator

  // Iterate through each query
  for (int i = 0; i < Q; i++) {
    // L: left index
    // R: right index
    // D: digit to replace
    int L, R, D;
    scanf("%d %d %d", &L, &R, &D);

    // Replace characters in S with D
    for (int j = L - 1; j < R; j++) {
      S[j] = D;
    }

    // Calculate the decimal value of S
    long long value = 0;
    for (int j = 0; j < N; j++) {
      value = (value * 10 + (S[j] - '0')) % MOD;
    }

    // Print the value modulo 998,244,353
    printf("%lld\n", value);
  }

  return 0;
}
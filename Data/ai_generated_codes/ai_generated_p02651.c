#include <stdio.h>
#include <string.h>

int main() {
  // T: Number of test cases
  int T;
  scanf("%d", &T);

  // Loop through each test case
  for (int t = 0; t < T; t++) {
    // N: Number of rounds
    int N;
    scanf("%d", &N);

    // A_i: Array of integers
    long long A[N];
    for (int i = 0; i < N; i++) {
      scanf("%lld", &A[i]);
    }

    // S: String of length N consisting of '0' and '1'
    char S[N + 1];
    scanf("%s", S);

    // x: Variable initialized to 0
    long long x = 0;

    // Loop through each round
    for (int i = 0; i < N; i++) {
      // If Person S_i is 1, they can choose to XOR x with A_i
      if (S[i] == '1') {
        // We assume Person 1 plays optimally and tries to make x non-zero
        x ^= A[i];
      }
      // If Person S_i is 0, they cannot do anything
    }

    // Check if x is 0 at the end of the game
    if (x == 0) {
      printf("0\n");
    } else {
      printf("1\n");
    }
  }

  return 0;
}
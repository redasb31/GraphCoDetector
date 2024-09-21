#include <stdio.h>

int main() {
  // Declare variables for the initial number of cookies and the number of operations.
  long long A, B, K;

  // Read the input values.
  scanf("%lld %lld %lld", &A, &B, &K);

  // Perform the operations alternately.
  for (int i = 0; i < K; i++) {
    // Takahashi's turn.
    if (A % 2 == 1) { // If Takahashi has an odd number of cookies, he eats one.
      A--;
    }
    B += A / 2; // Takahashi gives half his cookies to Aoki.
    A /= 2;

    // Aoki's turn.
    if (B % 2 == 1) { // If Aoki has an odd number of cookies, she eats one.
      B--;
    }
    A += B / 2; // Aoki gives half her cookies to Takahashi.
    B /= 2;
  }

  // Print the final number of cookies for Takahashi and Aoki.
  printf("%lld %lld\n", A, B);

  return 0;
}
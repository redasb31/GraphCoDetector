#include <stdio.h>

int main() {
  long long A, B, K; // Using long long to handle large values

  // Input: Read the number of cookies Takahashi and Aoki have, and the number of actions
  scanf("%lld %lld %lld", &A, &B, &K);

  // Process the actions
  for (long long i = 0; i < K; i++) {
    if (A > 0) { // Takahashi has cookies, so he eats one
      A--;
    } else if (B > 0) { // Takahashi has no cookies, but Aoki has, so Takahashi eats one of Aoki's
      B--;
    }
    // If both have no cookies, do nothing
  }

  // Output: Print the number of cookies Takahashi and Aoki have after the actions
  printf("%lld %lld\n", A, B);

  return 0;
}
#include <stdio.h>

int main() {
  // Declare variables to store the number of each type of cookie.
  long long A, B, C;

  // Read the number of cookies from the standard input.
  scanf("%lld %lld %lld", &A, &B, &C);

  // Calculate the maximum number of tasty cookies that can be eaten.
  // We can eat all the tasty cookies with antidotes.
  // We can also eat one tasty cookie with poison for each untasty cookie with antidote.
  long long maxTasty = B + (A < C ? A : C);

  // Print the result.
  printf("%lld\n", maxTasty);

  return 0;
}
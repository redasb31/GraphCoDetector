#include <stdio.h>

int main() {
  long long X, Y;
  scanf("%lld %lld", &X, &Y);

  // Check if X is a multiple of Y
  if (X % Y == 0) {
    // If X is a multiple of Y, there's no solution
    printf("-1\n");
  } else {
    // If X is not a multiple of Y, X itself is a valid solution
    printf("%lld\n", X);
  }

  return 0;
}
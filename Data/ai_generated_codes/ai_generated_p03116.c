#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input
  int N;
  scanf("%d", &N);

  long long *x = malloc(sizeof(long long) * N);
  long long *y = malloc(sizeof(long long) * N);

  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &x[i], &y[i]);
  }

  // Calculate X and Y
  long long X = x[0], Y = y[0];

  for (int i = 1; i < N; i++) {
    // Check if x[i] - X is odd and y[i] - Y is even
    if ((x[i] - X) % 2 != 0 && (y[i] - Y) % 2 == 0) {
      // If so, adjust Y to match the parity
      Y++;
    } else if ((x[i] - X) % 2 == 0 && (y[i] - Y) % 2 != 0) {
      // If so, adjust X to match the parity
      X++;
    }
  }

  // Output X and Y
  printf("%lld %lld\n", X, Y);

  free(x);
  free(y);

  return 0;
}
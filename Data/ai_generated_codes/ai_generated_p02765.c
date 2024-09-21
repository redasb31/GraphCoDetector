#include <stdio.h>

int main() {
  // Declare variables for the number of contests and the displayed rating.
  int N, R;

  // Read the number of contests and the displayed rating from standard input.
  scanf("%d %d", &N, &R);

  // Calculate the inner rating.
  int innerRating = R;
  if (N < 10) {
    innerRating += 100 * (10 - N);
  }

  // Print the inner rating.
  printf("%d\n", innerRating);

  return 0;
}
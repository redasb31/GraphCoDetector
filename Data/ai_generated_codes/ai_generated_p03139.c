#include <stdio.h>

int main() {
  // N: Total number of respondents
  // A: Number of respondents subscribing to Newspaper X
  // B: Number of respondents subscribing to Newspaper Y
  int N, A, B;

  // Read input values
  scanf("%d %d %d", &N, &A, &B);

  // Maximum possible number of respondents subscribing to both newspapers
  // This occurs when all respondents subscribing to Newspaper X also subscribe to Newspaper Y
  int max = (A < B) ? A : B;

  // Minimum possible number of respondents subscribing to both newspapers
  // This occurs when the overlap between respondents subscribing to Newspaper X and Y is minimized
  int min = (A + B) - N;

  // If the calculated minimum is negative, set it to 0
  if (min < 0) {
    min = 0;
  }

  // Print the maximum and minimum values
  printf("%d %d\n", max, min);

  return 0;
}
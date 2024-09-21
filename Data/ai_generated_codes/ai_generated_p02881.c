#include <stdio.h>
#include <math.h>

// Function to calculate the minimum moves required to reach a square containing N
int min_moves(long long N) {
  // Find the largest integer less than or equal to the square root of N
  long long sq = (long long)sqrt(N);

  // Calculate the difference between N and the square of the largest integer
  long long diff = N - (sq * sq);

  // If N is a perfect square, the minimum moves is simply sq - 1
  if (diff == 0) {
    return sq - 1;
  } else {
    // If N is not a perfect square, the minimum moves is the sum of sq and diff - 1
    return sq + diff - 1;
  }
}

int main() {
  long long N;

  // Read the input integer N
  scanf("%lld", &N);

  // Calculate and print the minimum moves required
  printf("%lld\n", min_moves(N));

  return 0;
}
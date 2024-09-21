#include <stdio.h>
#include <math.h>

// Function to check if N can be reduced to 1 using K
int canBecomeOne(long long N, long long K) {
  while (N >= K) {
    if (N % K == 0) {
      N /= K;
    } else {
      N -= K;
    }
  }
  return (N == 1);
}

int main() {
  long long N;
  scanf("%lld", &N); // Input N

  int count = 0; // Counter for valid K values
  for (long long K = 2; K <= N; K++) {
    if (canBecomeOne(N, K)) {
      count++;
    }
  }

  printf("%d\n", count); // Output the count

  return 0;
}
#include <stdio.h>

int main() {
  // N: The number of towns
  // K: The number of times the king uses the teleporter
  long long N, K;
  scanf("%lld %lld", &N, &K);

  // A: An array storing the destination town for each teleporter
  long long A[N];
  for (long long i = 0; i < N; i++) {
    scanf("%lld", &A + i);
    // Adjust the index to 0-based indexing for easier array access
    A[i]--; 
  }

  // currentTown: The current town the king is in
  long long currentTown = 0;

  // Using modulo operation to handle large K values efficiently
  K %= N; 

  // Simulate the teleporter usage for K times
  for (long long i = 0; i < K; i++) {
    currentTown = A[currentTown];
  }

  // Print the final town the king will be in
  printf("%lld\n", currentTown + 1);

  return 0;
}
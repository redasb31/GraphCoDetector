#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of operations required
long long findMinOperations(int N, int K, long long *H) {
  // Calculate the total number of squares to be painted
  long long totalSquares = 0;
  for (int i = 0; i < N; i++) {
    totalSquares += H[i];
  }

  // Sort the array H in descending order
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (H[i] < H[j]) {
        long long temp = H[i];
        H[i] = H[j];
        H[j] = temp;
      }
    }
  }

  // Calculate the minimum operations required
  long long operations = 0;
  int i = 0;
  while (totalSquares > 0) {
    // Find the maximum number of squares that can be painted in a row
    long long maxSquares = H[i];

    // If we have K columns left to change, choose the optimal strategy
    if (K > 0 && i < N - 1) {
      // If the next column has more squares to be painted, change it
      if (H[i + 1] > maxSquares) {
        K--;
        totalSquares -= H[i + 1] - maxSquares;
        H[i + 1] = maxSquares;
      }
    }

    // Paint the maximum number of squares in a row
    totalSquares -= maxSquares;
    operations++;

    // Move to the next column
    i++;
  }

  return operations;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  long long *H = (long long *)malloc(sizeof(long long) * N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &H[i]);
  }

  // Find the minimum number of operations required
  long long minOperations = findMinOperations(N, K, H);

  printf("%lld\n", minOperations);

  free(H);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to truncate a double towards zero
long long trunc(double x) {
  return x >= 0 ? (long long)x : (long long)x - 1;
}

int main() {
  // Read input
  long long N, Q, L, R;
  scanf("%lld %lld %lld %lld", &N, &Q, &L, &R);

  // Allocate memory for the array
  long long *A = (long long *)malloc(N * sizeof(long long));

  // Read array elements
  for (long long i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  // Process queries
  for (long long i = 0; i < Q; i++) {
    long long q, x, s, t;
    scanf("%lld %lld %lld %lld", &q, &x, &s, &t);

    // Query 1: Add and multiply
    if (q == 1) {
      for (long long j = 0; j < N; j++) {
        if (A[j] >= x) {
          A[j] = t * (A[j] + s);
        }
      }
    }
    // Query 2: Subtract and divide
    else if (q == 2) {
      for (long long j = 0; j < N; j++) {
        if (A[j] <= x) {
          A[j] = trunc((double)(A[j] - s) / t);
        }
      }
    }
  }

  // Count elements in the specified range
  long long count = 0;
  for (long long i = 0; i < N; i++) {
    if (A[i] >= L && A[i] <= R) {
      count++;
    }
  }

  // Print the count
  printf("%lld\n", count);

  // Free allocated memory
  free(A);

  return 0;
}
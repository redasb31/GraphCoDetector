#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
long long factorial(int n) {
  long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  // Allocate memory for the permutation array
  int *P = (int *)malloc(sizeof(int) * N);

  // Read the permutation from input
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }

  // Calculate the number of permutations that can be produced after the operation
  long long count = 0;
  for (int i = 0; i <= N - K; i++) {
    // Check if the elements in the window of size K are already sorted
    int sorted = 1;
    for (int j = i; j < i + K - 1; j++) {
      if (P[j] > P[j + 1]) {
        sorted = 0;
        break;
      }
    }

    // If the elements are not sorted, increment the count
    if (!sorted) {
      count++;
    }
  }

  // The final count is the factorial of K
  count = factorial(K) * count;

  // Print the count
  printf("%lld\n", count);

  // Free the allocated memory
  free(P);

  return 0;
}
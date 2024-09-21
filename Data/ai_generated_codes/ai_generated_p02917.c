#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int B[100];
  for (int i = 0; i < N - 1; i++) {
    scanf("%d", &B[i]);
  }

  // Initialize the maximum possible sum of A
  long long sum = 0;

  // Iterate through the sequence B
  for (int i = 0; i < N - 1; i++) {
    // If the current element of B is greater than or equal to the previous element,
    // we can assume that both A[i] and A[i+1] are equal to B[i] to maximize the sum
    if (B[i] >= (i > 0 ? B[i - 1] : 0)) {
      sum += B[i] * 2;
    } else {
      // Otherwise, we can assume that A[i] is equal to B[i] and A[i+1] is equal to the previous element of B
      sum += B[i] + (i > 0 ? B[i - 1] : 0);
    }
  }

  // Add the last element of A, which is equal to the last element of B
  sum += B[N - 2];

  printf("%lld\n", sum);

  return 0;
}
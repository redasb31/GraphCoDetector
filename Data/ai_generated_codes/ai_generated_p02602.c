#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read input values
  int N, K;
  scanf("%d %d", &N, &K);

  // Allocate memory for the array of scores
  long long *A = malloc(sizeof(long long) * N);

  // Read the scores from the input
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  // Calculate the product of the scores for the first K terms
  long long prev_product = 1;
  for (int i = 0; i < K; i++) {
    prev_product *= A[i];
  }

  // Iterate over the remaining terms and compare their grades
  for (int i = K; i < N; i++) {
    // Calculate the product of the scores for the current K terms
    long long current_product = prev_product / A[i - K] * A[i];

    // Compare the grades and print the output
    if (current_product > prev_product) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }

    // Update the previous product for the next iteration
    prev_product = current_product;
  }

  // Free allocated memory
  free(A);

  return 0;
}
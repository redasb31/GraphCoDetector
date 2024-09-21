#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  // Input: N (number of integers), K (k-th product)
  int N, K;
  scanf("%d %d", &N, &K);

  // Input: Array of integers A
  int *A = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the number of pairs
  int numPairs = (N * (N - 1)) / 2;

  // Check if K is valid
  if (K < 1 || K > numPairs) {
    printf("Invalid K\n");
    free(A);
    return 1;
  }

  // Create an array to store all pair products
  long long *products = (long long *)malloc(numPairs * sizeof(long long));
  int productIndex = 0;

  // Calculate all pair products
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      products[productIndex++] = (long long)A[i] * A[j];
    }
  }

  // Sort the products in ascending order
  qsort(products, numPairs, sizeof(long long), compare);

  // Print the K-th product
  printf("%lld\n", products[K - 1]);

  // Free allocated memory
  free(A);
  free(products);

  return 0;
}
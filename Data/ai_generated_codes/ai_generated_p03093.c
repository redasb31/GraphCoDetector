#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  // Allocate memory for the input array.
  int *a = malloc(2 * N * sizeof(int));

  // Read the input array.
  for (int i = 0; i < 2 * N; i++) {
    scanf("%d", &a[i]);
  }

  // Sort the input array in ascending order.
  qsort(a, 2 * N, sizeof(int), cmp);

  // Calculate the maximum ugliness.
  int Z = 0;
  for (int i = 0; i < N; i++) {
    Z = (Z > (a[i] + a[2 * N - 1 - i]) * M) ? Z : (a[i] + a[2 * N - 1 - i]) * M;
  }

  // Print the result.
  printf("%d\n", Z);

  // Free allocated memory.
  free(a);

  return 0;
}
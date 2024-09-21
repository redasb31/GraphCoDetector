#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input: Number of ears (L) and number of stones in each ear (A_i)
  int L, i, sum = 0;
  scanf("%d", &L);
  int *A = (int *)malloc(sizeof(int) * L);
  for (i = 0; i < L; i++) {
    scanf("%d", &A[i]);
    sum += A[i];
  }

  // Calculate the minimum number of operations
  int operations = abs(sum - L);

  // Print the result
  printf("%d\n", operations);

  // Free allocated memory
  free(A);

  return 0;
}
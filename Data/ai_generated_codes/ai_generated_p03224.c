#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: the number of elements
  int N;
  scanf("%d", &N);

  // If N is odd, no solution exists
  if (N % 2 != 0) {
    printf("No\n");
    return 0;
  }

  // Create a 2D array to store the subsets
  int **subsets;
  subsets = (int **)malloc(N / 2 * sizeof(int *));
  for (int i = 0; i < N / 2; i++) {
    subsets[i] = (int *)malloc(2 * sizeof(int));
  }

  // Fill the subsets
  for (int i = 0; i < N / 2; i++) {
    // First element of each subset
    subsets[i][0] = i + 1;
    // Second element of each subset
    subsets[i][1] = i + N / 2 + 1;
  }

  // Print the solution
  printf("Yes\n");
  printf("%d\n", N / 2);
  for (int i = 0; i < N / 2; i++) {
    printf("2 %d %d\n", subsets[i][0], subsets[i][1]);
  }

  // Free the allocated memory
  for (int i = 0; i < N / 2; i++) {
    free(subsets[i]);
  }
  free(subsets);

  return 0;
}
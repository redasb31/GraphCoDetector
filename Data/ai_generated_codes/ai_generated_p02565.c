#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  // Compare based on the smaller coordinate first, then the larger coordinate.
  int *x = (int *)a;
  int *y = (int *)b;
  if (x[0] != y[0]) {
    return x[0] - y[0];
  } else {
    return x[1] - y[1];
  }
}

int main() {
  int N, D;
  scanf("%d %d", &N, &D);

  // Store the coordinates of each flag.
  int **flags = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    flags[i] = (int *)malloc(2 * sizeof(int));
    scanf("%d %d", &flags[i][0], &flags[i][1]);
  }

  // Sort the flags based on their smaller coordinate.
  qsort(flags, N, sizeof(int *), cmp);

  // Check if it is possible to place all flags.
  int last_pos = -1;
  int possible = 1;
  for (int i = 0; i < N; i++) {
    // If the current flag's smaller coordinate is less than the last
    // flag's larger coordinate plus D, then it is not possible to
    // place this flag.
    if (flags[i][0] < last_pos + D) {
      possible = 0;
      break;
    }

    // Choose the larger coordinate to maximize the distance between flags.
    last_pos = flags[i][1];
  }

  // Output the result.
  if (possible) {
    printf("Yes\n");
    for (int i = 0; i < N; i++) {
      printf("%d\n", flags[i][1]);
    }
  } else {
    printf("No\n");
  }

  // Free memory.
  for (int i = 0; i < N; i++) {
    free(flags[i]);
  }
  free(flags);

  return 0;
}
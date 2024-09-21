#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  // Sort by the difference between Takahashi's happiness and Aoki's happiness.
  // We want Takahashi to maximize his happiness, so the larger the difference, the better.
  return (*(int *)b - *(int *)a);
}

int main() {
  int N;
  scanf("%d", &N);

  // Allocate memory for the dishes and store the happiness values.
  int *dishes = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    dishes[i] = A - B;
  }

  // Sort the dishes based on the difference in happiness.
  qsort(dishes, N, sizeof(int), compare);

  // Calculate the total happiness for Takahashi and Aoki.
  long long takahashi_happiness = 0;
  long long aoki_happiness = 0;
  for (int i = 0; i < N; i++) {
    // Takahashi gets the dishes with the largest difference.
    if (i % 2 == 0) {
      takahashi_happiness += dishes[i] + abs(dishes[i]);
    } else {
      // Aoki gets the dishes with the smallest difference.
      aoki_happiness += dishes[i] + abs(dishes[i]);
    }
  }

  // Output the difference in happiness.
  printf("%lld\n", takahashi_happiness - aoki_happiness);

  free(dishes);
  return 0;
}
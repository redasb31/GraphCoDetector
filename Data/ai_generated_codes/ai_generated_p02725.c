#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  // Input: K - perimeter, N - number of houses, A - array of distances
  int K, N;
  scanf("%d %d", &K, &N);
  int *A = (int *)malloc(sizeof(int) * N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Sort the distances for efficient traversal
  qsort(A, N, sizeof(int), compare);

  // Calculate distances between houses
  int distances[N];
  for (int i = 0; i < N - 1; i++) {
    distances[i] = A[i + 1] - A[i];
  }
  distances[N - 1] = K - (A[N - 1] - A[0]);

  // Find the minimum distance by considering all possible starting points
  int minDistance = K; // Initialize with the maximum possible distance
  for (int i = 0; i < N; i++) {
    int totalDistance = 0;
    for (int j = 0; j < N; j++) {
      totalDistance += distances[(i + j) % N];
    }
    if (totalDistance < minDistance) {
      minDistance = totalDistance;
    }
  }

  printf("%d\n", minDistance);

  free(A);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Function to calculate the distance between two points on the circumference
int distance(int a, int b, int L) {
  int diff = abs(a - b);
  return min(diff, L - diff);
}

int main() {
  int L, N;
  scanf("%d %d", &L, &N);

  // Store the coordinates of the trees
  int *X = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }

  // Sort the tree coordinates in ascending order
  qsort(X, N, sizeof(int), (int(*)(const void *, const void *))distance);

  // Initialize the total distance to 0
  int totalDistance = 0;

  // Iterate through the trees
  for (int i = 0; i < N; i++) {
    // Calculate the distance to the next tree
    int nextTreeDistance = distance(X[i], X[(i + 1) % N], L);

    // Calculate the distance to the previous tree
    int prevTreeDistance = distance(X[i], X[(i - 1 + N) % N], L);

    // Choose the direction with the longer distance
    int maxDistance = max(nextTreeDistance, prevTreeDistance);

    // Update the total distance
    totalDistance += maxDistance;
  }

  // Print the total distance
  printf("%d\n", totalDistance);

  // Free the allocated memory
  free(X);

  return 0;
}
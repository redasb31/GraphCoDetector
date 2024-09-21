#include <stdio.h>
#include <stdlib.h>

// Function to calculate the distance between the two result stones
int calculateDistance(int *stones, int n) {
  // Sort the stones in ascending order
  qsort(stones, n, sizeof(int), compare);

  // The distance between the two result stones is the difference between the last and second last stones
  return stones[n - 1] - stones[n - 2];
}

// Function to compare two integers for qsort()
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  int n, i;
  char firstPlayer[10];
  // Read the number of stones and the first player's name
  scanf("%d %s", &n, firstPlayer);

  // Allocate memory for the stones
  int *stones = (int *)malloc(n * sizeof(int));

  // Read the coordinates of the stones
  for (i = 0; i < n; i++) {
    scanf("%d", &stones[i]);
  }

  // Calculate the distance between the result stones
  int distance = calculateDistance(stones, n);

  // Print the distance between the result stones
  printf("%d\n", distance);

  // Free the allocated memory
  free(stones);

  return 0;
}
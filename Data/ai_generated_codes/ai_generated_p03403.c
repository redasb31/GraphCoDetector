#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  scanf("%d", &N);

  // Allocate memory for the array of coordinates
  int *A = (int *)malloc(N * sizeof(int));

  // Read the coordinates of the spots
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the total cost for each case
  for (int i = 0; i < N; i++) {
    // Calculate the cost of traveling to the spots before the canceled spot
    int cost1 = 0;
    for (int j = 0; j < i; j++) {
      cost1 += abs(A[j]);
    }

    // Calculate the cost of traveling from the canceled spot to the remaining spots
    int cost2 = 0;
    for (int j = i + 1; j < N; j++) {
      cost2 += abs(A[j] - A[j - 1]);
    }

    // Calculate the total cost for the trip
    int totalCost = cost1 + cost2 + abs(A[N - 1]);

    // Print the total cost for the current case
    printf("%d\n", totalCost);
  }

  // Free the allocated memory
  free(A);

  return 0;
}
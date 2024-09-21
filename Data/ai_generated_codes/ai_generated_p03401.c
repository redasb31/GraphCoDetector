#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input:
  int N; // Number of sightseeing spots
  scanf("%d", &N);

  int *A = (int *)malloc(sizeof(int) * N); // Array to store coordinates of spots
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate total cost for each spot being skipped:
  for (int i = 0; i < N; i++) {
    int cost = 0; // Total travel cost
    // Calculate cost for the trip before skipping spot i:
    for (int j = 0; j < i; j++) {
      cost += abs(A[j] - A[j + 1]);
    }
    // Calculate cost for the trip after skipping spot i:
    for (int j = i + 1; j < N; j++) {
      cost += abs(A[j - 1] - A[j]);
    }
    // Calculate cost for returning to origin:
    cost += abs(A[N - 1]);
    // Print the total cost:
    printf("%d\n", cost);
  }

  free(A);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum total comfort
long long findMaxComfort(int N, int* A) {
  // Sort the friendliness values in descending order
  qsort(A, N, sizeof(int), 
    (int (*)(const void*, const void*))
    (int) (
      (const int* a, const int* b) -> int { 
        return *b - *a; 
      }
    )
  );

  // Initialize the maximum total comfort
  long long maxComfort = 0;

  // Calculate the comfort for each player
  for (int i = 1; i < N; i++) {
    // The comfort is the smaller of the two adjacent friendliness values
    maxComfort += (A[i - 1] < A[i]) ? A[i - 1] : A[i];
  }

  // Return the maximum total comfort
  return maxComfort;
}

int main() {
  // Read the number of players
  int N;
  scanf("%d", &N);

  // Allocate memory for the friendliness values
  int* A = (int*) malloc(N * sizeof(int));

  // Read the friendliness values
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Find the maximum total comfort
  long long maxComfort = findMaxComfort(N, A);

  // Print the maximum total comfort
  printf("%lld\n", maxComfort);

  // Free the allocated memory
  free(A);

  return 0;
}
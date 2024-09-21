#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum happiness points
long long calculateHappiness(int N, int *A) {
  // Sort the activeness values in descending order
  // This is because the child with the highest activeness should move the furthest
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[i] < A[j]) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
    }
  }

  // Calculate the happiness points
  long long happiness = 0;
  for (int i = 0; i < N; i++) {
    // The child at index i moves to index (N - 1 - i)
    happiness += A[i] * abs(i - (N - 1 - i));
  }

  return happiness;
}

int main() {
  int N;
  scanf("%d", &N);

  int *A = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate and print the maximum happiness points
  long long maxHappiness = calculateHappiness(N, A);
  printf("%lld\n", maxHappiness);

  free(A);

  return 0;
}
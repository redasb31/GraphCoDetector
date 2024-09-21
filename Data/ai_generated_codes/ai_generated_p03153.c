#include <stdio.h>
#include <stdlib.h>

// Function to calculate the cost of building a road between cities i and j
long long road_cost(int i, int j, int *A, int D) {
  return abs(i - j) * D + A[i - 1] + A[j - 1];
}

// Function to find the minimum cost of connecting all cities
long long minimum_cost(int N, int D, int *A) {
  // Sort the cities by size in ascending order
  // This optimization is based on the fact that it's generally cheaper to connect smaller cities first
  // Sorting uses quick sort algorithm
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[i] > A[j]) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
    }
  }

  // Initialize the total cost
  long long total_cost = 0;

  // Connect each city to the previously connected city
  for (int i = 1; i < N; i++) {
    total_cost += road_cost(i, i - 1, A, D);
  }

  // Return the total cost
  return total_cost;
}

int main() {
  // Read the number of cities and the cost per unit distance
  int N, D;
  scanf("%d %d", &N, &D);

  // Read the size of each city
  int *A = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate and print the minimum cost
  long long min_cost = minimum_cost(N, D, A);
  printf("%lld\n", min_cost);

  // Free the allocated memory
  free(A);

  return 0;
}
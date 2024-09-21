#include <stdio.h>
#include <limits.h>

#define MAX_N 100000

int main() {
  // Input variables
  int A, B, M;
  int a[MAX_N], b[MAX_N];
  int x[MAX_N], y[MAX_N], c[MAX_N];

  // Read the input
  scanf("%d %d %d", &A, &B, &M);
  for (int i = 0; i < A; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < B; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &x[i], &y[i], &c[i]);
  }

  // Initialize the minimum cost to the maximum possible value
  int min_cost = INT_MAX;

  // Iterate over all possible refrigerator and microwave combinations
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      // Calculate the cost without any discount
      int cost = a[i] + b[j];

      // Iterate over all discount tickets
      for (int k = 0; k < M; k++) {
        // If the ticket is applicable to the current combination
        if (x[k] == i + 1 && y[k] == j + 1) {
          // Update the cost if the discounted price is lower
          cost = cost - c[k];
          break; // Only one ticket can be used at a time
        }
      }

      // Update the minimum cost if the current cost is lower
      min_cost = (cost < min_cost) ? cost : min_cost;
    }
  }

  // Print the minimum cost
  printf("%d\n", min_cost);

  return 0;
}
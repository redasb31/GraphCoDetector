#include <stdio.h>
#include <limits.h>

#define MAX_N 12
#define MAX_M 12

int main() {
  int N, M, X;
  int C[MAX_N];
  int A[MAX_N][MAX_M];

  // Read input
  scanf("%d %d %d", &N, &M, &X);
  for (int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
    for (int j = 0; j < M; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Initialize minimum cost to a large value
  int min_cost = INT_MAX;

  // Iterate through all possible combinations of books
  for (int i = 0; i < (1 << N); i++) {
    int cost = 0;
    int understanding[MAX_M] = {0};
    // Check if the current combination of books satisfies the conditions
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        cost += C[j];
        for (int k = 0; k < M; k++) {
          understanding[k] += A[j][k];
        }
      }
    }
    // Check if all understanding levels are at least X
    int all_satisfied = 1;
    for (int j = 0; j < M; j++) {
      if (understanding[j] < X) {
        all_satisfied = 0;
        break;
      }
    }
    // Update minimum cost if the current combination is better
    if (all_satisfied) {
      min_cost = (cost < min_cost) ? cost : min_cost;
    }
  }

  // Print the result
  if (min_cost == INT_MAX) {
    printf("-1\n");
  } else {
    printf("%d\n", min_cost);
  }

  return 0;
}
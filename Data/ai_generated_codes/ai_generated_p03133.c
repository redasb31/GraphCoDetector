#include <stdio.h>
#define MOD 998244353

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  // Matrix to store the input
  int grid[300][300];

  // Read the input
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  // Calculate the number of odd sums for each row and column
  int row_odd[300] = {0}; // Stores the number of odd sums in each row
  int col_odd[300] = {0}; // Stores the number of odd sums in each column
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 1) {
        row_odd[i]++;
        col_odd[j]++;
      }
    }
  }

  // Calculate the total number of pairs with odd sums
  long long total_pairs = 0; // Use long long to handle potential overflow
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // Calculate the number of pairs with an odd sum if we include row i and column j
      long long odd_pairs = (row_odd[i] * col_odd[j]) % MOD;
      // Calculate the number of pairs with an even sum if we include row i and column j
      long long even_pairs = (((N - row_odd[i]) * (M - col_odd[j])) % MOD);
      // Total pairs is the sum of pairs with odd sum and even sum
      total_pairs = (total_pairs + odd_pairs + even_pairs) % MOD;
    }
  }

  // Print the result modulo 998244353
  printf("%lld\n", total_pairs);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500

int N;
char grid[MAX_N][MAX_N];

int is_empty(int i, int j) {
  return grid[i][j] != '#';
}

long long calculate_sum_of_products() {
  long long sum = 0;

  // Iterate over all cells
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // If the current cell is empty, check for reachable cells
      if (is_empty(i, j)) {
        // Iterate over all reachable cells
        for (int k = i + 1; k < N; k++) {
          if (is_empty(k, j)) {
            sum += (grid[i][j] - '0') * (grid[k][j] - '0');
          }
        }
        for (int k = j + 1; k < N; k++) {
          if (is_empty(i, k)) {
            sum += (grid[i][j] - '0') * (grid[i][k] - '0');
          }
        }
      }
    }
  }

  return sum;
}

int main() {
  // Read input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", grid[i]);
  }

  // Calculate the sum of products
  long long sum = calculate_sum_of_products();

  // Print the result
  printf("%lld\n", sum);

  return 0;
}
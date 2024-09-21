#include <stdio.h>

// Function to calculate the minimum value in a row or column
int min_in_row_col(int grid[][100], int N, int M, int row, int col) {
  int min = grid[row][col];
  // Iterate through the row
  for (int i = 0; i < M; i++) {
    min = (min < grid[row][i]) ? min : grid[row][i];
  }
  // Iterate through the column
  for (int i = 0; i < N; i++) {
    min = (min < grid[i][col]) ? min : grid[i][col];
  }
  return min;
}

// Function to calculate the product of the minimum values in each cell
int calculate_product(int grid[][100], int N, int M) {
  int product = 1;
  // Iterate through all cells in the grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      product *= min_in_row_col(grid, N, M, i, j);
    }
  }
  return product;
}

// Function to calculate the sum of the products for all possible grid configurations
long long calculate_sum(int N, int M, int K, int D) {
  long long sum = 0;
  // Initialize a grid to store the values
  int grid[100][100];
  // Iterate through all possible values for each cell in the grid
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      // Fill the grid with current values
      for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
          grid[row][col] = (row == i && col == j) ? K : 0;
        }
      }
      // Calculate the product for this grid configuration
      int product = calculate_product(grid, N, M);
      // Add the product to the sum
      sum = (sum + product) % D;
    }
  }
  return sum;
}

int main() {
  int N, M, K, D;
  scanf("%d %d %d %d", &N, &M, &K, &D);
  long long sum = calculate_sum(N, M, K, D);
  printf("%lld\n", sum);
  return 0;
}
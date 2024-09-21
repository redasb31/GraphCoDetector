#include <stdio.h>

int main() {
  // N: The number of columns in the grid
  int N;
  // A[i][j]: The number of candies in the square (i, j)
  int A[2][100]; 

  // Read the input
  scanf("%d", &N);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // dp[i][j]: The maximum number of candies that can be collected when you reach the square (i, j)
  int dp[2][100]; 

  // Initialize the dp array
  dp[0][0] = A[0][0]; 
  dp[1][0] = A[1][0];

  // Calculate the maximum number of candies that can be collected for each square
  for (int j = 1; j < N; j++) {
    // The maximum number of candies collected when reaching (0, j) is the maximum of the number of candies collected when reaching (0, j-1) + the number of candies at (0, j)
    dp[0][j] = dp[0][j-1] + A[0][j];
    // The maximum number of candies collected when reaching (1, j) is the maximum of the number of candies collected when reaching (1, j-1) + the number of candies at (1, j)
    dp[1][j] = dp[1][j-1] + A[1][j];
  }

  // The maximum number of candies collected when reaching the bottom-right square (2, N) is the maximum of the number of candies collected when reaching (1, N-1) + the number of candies at (2, N) and the number of candies collected when reaching (0, N-1) + the number of candies at (2, N)
  int maxCandies = dp[0][N-1] + A[1][N-1];
  maxCandies = maxCandies > (dp[1][N-1] + A[0][N-1]) ? maxCandies : (dp[1][N-1] + A[0][N-1]);

  // Print the maximum number of candies that can be collected
  printf("%d\n", maxCandies);

  return 0;
}
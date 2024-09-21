#include <stdio.h>
#include <stdlib.h>

// Function to find the length of the longest arithmetic progression
int longest_arithmetic_progression(int *arr, int n) {
  // Create a 2D array to store the lengths of arithmetic progressions ending at each index
  int **dp = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    dp[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      dp[i][j] = 0;
    }
  }

  // Initialize the DP array for base cases
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1; // Each element forms an arithmetic progression of length 1
  }

  // Iterate through the array and update the DP array
  int max_length = 1; // Initialize the maximum length to 1
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      // Calculate the common difference
      int diff = arr[i] - arr[j];
      // Find the previous element with the same common difference
      int prev = j;
      while (prev >= 0 && arr[i] - arr[prev] == diff) {
        // Update the length of the arithmetic progression ending at index i
        dp[i][j] = dp[prev][j] + 1;
        max_length = (dp[i][j] > max_length) ? dp[i][j] : max_length;
        prev--;
      }
    }
  }

  // Free the memory allocated for the DP array
  for (int i = 0; i < n; i++) {
    free(dp[i]);
  }
  free(dp);

  return max_length;
}

int main() {
  int n;
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));

  // Read the input array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Find the length of the longest arithmetic progression
  int length = longest_arithmetic_progression(arr, n);

  // Print the output
  printf("%d\n", length);

  // Free the memory allocated for the input array
  free(arr);

  return 0;
}
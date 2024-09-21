#include <stdio.h>

// Function to calculate the maximum possible sum of jewels in hand after operations
int maxJewelSum(int N, int K, int V[]) {
  // Initialize the maximum sum to 0
  int maxSum = 0;

  // Calculate the maximum sum of jewels in hand after operations
  for (int i = 0; i < N; i++) {
    // Calculate the sum of jewels in hand after taking out the jewels from the left and right ends
    int sum = V[i] + V[N - 1 - i];

    // Update the maximum sum if the current sum is greater
    if (sum > maxSum) {
      maxSum = sum;
    }
  }

  // Return the maximum sum of jewels in hand
  return maxSum;
}

int main() {
  // Declare variables for the number of jewels, number of operations, and the array of jewel values
  int N, K;
  int V[50];

  // Read the number of jewels and operations from the standard input
  scanf("%d %d", &N, &K);

  // Read the array of jewel values from the standard input
  for (int i = 0; i < N; i++) {
    scanf("%d", &V[i]);
  }

  // Print the maximum possible sum of jewels in hand after operations
  printf("%d\n", maxJewelSum(N, K, V));

  return 0;
}
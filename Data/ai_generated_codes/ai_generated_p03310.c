#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum absolute difference between the maximum and minimum sums
int min_diff(int *A, int N) {
  // Calculate the prefix sum array
  int *prefix_sum = (int *)malloc(sizeof(int) * (N + 1));
  prefix_sum[0] = 0;
  for (int i = 1; i <= N; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
  }

  // Initialize the minimum difference to the maximum possible value
  int min_diff = prefix_sum[N];

  // Iterate over all possible positions of the first cut
  for (int i = 1; i <= N - 3; i++) {
    // Iterate over all possible positions of the second cut
    for (int j = i + 1; j <= N - 2; j++) {
      // Iterate over all possible positions of the third cut
      for (int k = j + 1; k <= N - 1; k++) {
        // Calculate the sums of the four subsequences
        int sum1 = prefix_sum[i] - prefix_sum[0];
        int sum2 = prefix_sum[j] - prefix_sum[i];
        int sum3 = prefix_sum[k] - prefix_sum[j];
        int sum4 = prefix_sum[N] - prefix_sum[k];

        // Find the maximum and minimum sums
        int max_sum = sum1 > sum2 ? sum1 : sum2;
        max_sum = max_sum > sum3 ? max_sum : sum3;
        max_sum = max_sum > sum4 ? max_sum : sum4;
        int min_sum = sum1 < sum2 ? sum1 : sum2;
        min_sum = min_sum < sum3 ? min_sum : sum3;
        min_sum = min_sum < sum4 ? min_sum : sum4;

        // Update the minimum difference
        min_diff = min_diff < abs(max_sum - min_sum) ? min_diff : abs(max_sum - min_sum);
      }
    }
  }

  // Free the allocated memory
  free(prefix_sum);

  // Return the minimum difference
  return min_diff;
}

int main() {
  int N;
  scanf("%d", &N);

  int *A = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  int min_abs_diff = min_diff(A, N);
  printf("%d\n", min_abs_diff);

  free(A);
  return 0;
}
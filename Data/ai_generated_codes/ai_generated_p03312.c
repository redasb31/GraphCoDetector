#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum absolute difference
int min_abs_diff(long long int *arr, int n) {
  // Calculate the sum of all elements in the array
  long long int total_sum = 0;
  for (int i = 0; i < n; i++) {
    total_sum += arr[i];
  }

  // Find the minimum absolute difference
  long long int min_diff = total_sum;
  for (int i = 1; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        // Calculate the sums of the four subsequences
        long long int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        for (int l = 0; l < i; l++) {
          sum1 += arr[l];
        }
        for (int l = i; l < j; l++) {
          sum2 += arr[l];
        }
        for (int l = j; l < k; l++) {
          sum3 += arr[l];
        }
        for (int l = k; l < n; l++) {
          sum4 += arr[l];
        }

        // Calculate the absolute difference between the maximum and minimum sums
        long long int max_sum = sum1;
        long long int min_sum = sum1;
        if (sum2 > max_sum) {
          max_sum = sum2;
        }
        if (sum3 > max_sum) {
          max_sum = sum3;
        }
        if (sum4 > max_sum) {
          max_sum = sum4;
        }
        if (sum2 < min_sum) {
          min_sum = sum2;
        }
        if (sum3 < min_sum) {
          min_sum = sum3;
        }
        if (sum4 < min_sum) {
          min_sum = sum4;
        }
        long long int diff = max_sum - min_sum;

        // Update the minimum difference if necessary
        if (diff < min_diff) {
          min_diff = diff;
        }
      }
    }
  }

  return min_diff;
}

int main() {
  int n;
  scanf("%d", &n);

  // Allocate memory for the array
  long long int *arr = (long long int *)malloc(sizeof(long long int) * n);

  // Read the array elements
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  // Calculate and print the minimum absolute difference
  printf("%lld\n", min_abs_diff(arr, n));

  // Free the allocated memory
  free(arr);

  return 0;
}
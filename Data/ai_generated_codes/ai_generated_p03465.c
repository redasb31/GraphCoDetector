#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of all non-empty subsequences of the given array
long long calculate_sum_of_subsequences(int *arr, int n) {
  long long sum = 0;
  // Looping through all possible subsequences
  for (int i = 1; i < (1 << n); i++) {
    // Calculating the sum of the current subsequence
    long long sub_sum = 0;
    for (int j = 0; j < n; j++) {
      // Checking if the j-th element is included in the current subsequence
      if ((i >> j) & 1) {
        sub_sum += arr[j];
      }
    }
    // Adding the sum of the current subsequence to the total sum
    sum += sub_sum;
  }
  return sum;
}

int main() {
  // Reading the number of elements in the array
  int n;
  scanf("%d", &n);
  // Allocating memory for the array
  int *arr = (int *)malloc(n * sizeof(int));
  // Reading the elements of the array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  // Calculating the sum of all non-empty subsequences
  long long sum = calculate_sum_of_subsequences(arr, n);
  // Calculating the median (the sum of all non-empty subsequences divided by 2^(n-1))
  long long median = sum / (1 << (n - 1));
  // Printing the median
  printf("%lld\n", median);
  // Freeing the allocated memory
  free(arr);
  return 0;
}
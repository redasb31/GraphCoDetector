#include <stdio.h>

// Function to perform counting sort
void countingSort(int arr[], int n, int k) {
  // Create an auxiliary array to store counts
  int count[k + 1];

  // Initialize the count array to 0
  for (int i = 0; i <= k; i++) {
    count[i] = 0;
  }

  // Count the occurrences of each element
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  // Calculate the cumulative count
  for (int i = 1; i <= k; i++) {
    count[i] += count[i - 1];
  }

  // Create an output array to store sorted elements
  int output[n];

  // Place elements in the output array based on their count
  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // Copy the sorted elements back to the original array
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

int main() {
  int n; // Number of elements in the array
  int k = 10000; // Maximum value in the array (given constraint)

  // Input the number of elements
  scanf("%d", &n);

  // Input the array elements
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Perform counting sort
  countingSort(arr, n, k);

  // Print the sorted array
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      printf(" ");
    }
    printf("%d", arr[i]);
  }
  printf("\n");

  return 0;
}
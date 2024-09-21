#include <stdio.h>

// Function to merge two sorted subarrays and count inversions
long long merge(int arr[], int temp[], int left, int mid, int right) {
  int i = left, j = mid + 1, k = left;
  long long inv_count = 0;

  // Merge the two subarrays while counting inversions
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      // If arr[i] > arr[j], then all elements from i to mid are greater than arr[j]
      inv_count += (mid - i + 1);
    }
  }

  // Copy remaining elements from the left subarray
  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  // Copy remaining elements from the right subarray
  while (j <= right) {
    temp[k++] = arr[j++];
  }

  // Copy the merged array back to the original array
  for (i = left; i <= right; i++) {
    arr[i] = temp[i];
  }

  return inv_count;
}

// Function to perform merge sort and count inversions
long long mergeSort(int arr[], int temp[], int left, int right) {
  long long inv_count = 0;
  if (left < right) {
    int mid = (left + right) / 2;

    // Recursively sort the left and right subarrays
    inv_count += mergeSort(arr, temp, left, mid);
    inv_count += mergeSort(arr, temp, mid + 1, right);

    // Merge the sorted subarrays and count inversions
    inv_count += merge(arr, temp, left, mid, right);
  }
  return inv_count;
}

int main() {
  int n, i;
  long long inv_count;
  scanf("%d", &n);
  int arr[n];
  int temp[n]; // Temporary array for merge sort

  // Read the array elements
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Count inversions using merge sort
  inv_count = mergeSort(arr, temp, 0, n - 1);

  // Print the number of inversions
  printf("%lld\n", inv_count);

  return 0;
}
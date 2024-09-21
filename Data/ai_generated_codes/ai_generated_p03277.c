#include <stdio.h>
#include <stdlib.h>

// Function to find the median of a given array
int findMedian(int *arr, int n) {
  // Sort the array in ascending order
  qsort(arr, n, sizeof(int), (int(*)(const void *, const void *))  
  
  // If the number of elements is even, return the average of the middle two elements
  if (n % 2 == 0) {
    return (arr[n / 2 - 1] + arr[n / 2]) / 2;
  } else {
    // If the number of elements is odd, return the middle element
    return arr[n / 2];
  }
}

int main() {
  int n;
  scanf("%d", &n);

  // Declare an array to store the input sequence
  int a[n];

  // Read the input sequence
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Declare an array to store the medians of all contiguous subsequences
  int m[n * (n + 1) / 2];

  // Calculate the medians of all contiguous subsequences and store them in the array m
  int k = 0;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      // Create a temporary array to store the current subsequence
      int subseq[r - l + 1];
      for (int i = l; i <= r; i++) {
        subseq[i - l] = a[i];
      }

      // Find the median of the current subsequence and store it in the array m
      m[k++] = findMedian(subseq, r - l + 1);
    }
  }

  // Find the median of the array m
  int median = findMedian(m, k);

  // Print the median
  printf("%d\n", median);

  return 0;
}
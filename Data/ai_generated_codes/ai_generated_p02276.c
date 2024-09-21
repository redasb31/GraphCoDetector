#include <stdio.h>

// Function to partition the array around a pivot element
int partition(int A[], int p, int r) {
  // Select the last element as the pivot
  int x = A[r];
  
  // Initialize the index of the smaller element
  int i = p - 1;

  // Iterate through the array from the first element to the pivot element
  for (int j = p; j <= r - 1; j++) {
    // If the current element is less than or equal to the pivot
    if (A[j] <= x) {
      // Increment the index of the smaller element
      i = i + 1;
      // Swap the current element with the element at the index of the smaller element
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  // Swap the pivot element with the element at the index of the smaller element + 1
  int temp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = temp;

  // Return the index of the pivot element
  return i + 1;
}

int main() {
  int n;
  scanf("%d", &n);

  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  // Perform partition on the array
  int q = partition(A, 0, n - 1);

  // Print the sorted array with the pivot element indicated by [ ]
  for (int i = 0; i < n; i++) {
    if (i == q) {
      printf("[%d] ", A[i]);
    } else {
      printf("%d ", A[i]);
    }
  }
  printf("\n");

  return 0;
}
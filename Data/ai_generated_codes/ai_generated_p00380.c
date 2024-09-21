#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if the array is sorted in ascending order
int isSorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] > arr[i]) {
      return 0; // Not sorted
    }
  }
  return 1; // Sorted
}

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int main() {
  int n, q;
  scanf("%d", &n); // Number of elements in the array

  // Allocate memory for the array
  int *arr = (int *)malloc(n * sizeof(int));
  
  // Read the array elements
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  scanf("%d", &q); // Number of swap commands

  // Check if the initial array is sorted
  if (isSorted(arr, n)) {
    printf("0\n");
    free(arr);
    return 0;
  }

  // Read the swap commands
  int x, y;
  int count = 0;
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &x, &y);
    x--; // Adjust indices to 0-based
    y--;

    // Swap the elements
    swap(arr, x, y);
    count++;

    // Check if the array is sorted after the swap
    if (isSorted(arr, n)) {
      printf("%d\n", count);
      free(arr);
      return 0;
    }
  }

  // If the array is not sorted after all the swaps
  printf("-1\n");
  free(arr);
  return 0;
}
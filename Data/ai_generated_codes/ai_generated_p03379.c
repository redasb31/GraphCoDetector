#include <stdio.h>
#include <stdlib.h>

// Function to find the median of an array
int findMedian(int arr[], int n) {
  // Sort the array in ascending order
  qsort(arr, n, sizeof(int), (int(*)(const void*, const void*))  // Sorting function in C
    // Custom comparison function for ascending order
    int compare(const void *a, const void *b) { 
      return (*(int*)a - *(int*)b);
    }
  );

  // Return the middle element (median)
  return arr[n / 2]; 
}

int main() {
  int N;
  // Read the number of elements (N)
  scanf("%d", &N);

  int X[N];
  // Read the elements of the array
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
  }

  // Create a temporary array to store the elements excluding X[i]
  int temp[N - 1]; 
  
  // Iterate through each element X[i]
  for (int i = 0; i < N; i++) {
    // Copy the elements excluding X[i] to the temporary array
    int j = 0;
    for (int k = 0; k < N; k++) {
      if (k != i) {
        temp[j] = X[k];
        j++;
      }
    }

    // Calculate and print the median B[i]
    printf("%d\n", findMedian(temp, N - 1)); 
  }

  return 0;
}
#include <stdio.h>
#include <limits.h>

// Function to find the minimum of a sub-array
int find_min(int *arr, int start, int end) {
  int min = INT_MAX;
  for (int i = start; i <= end; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int main() {
  int N, L; // N: size of the array, L: size of the sub-array
  scanf("%d %d", &N, &L);

  // Declare an array to store the input elements
  int arr[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  // Find the minimum of each sub-array and print it
  for (int i = 0; i <= N - L; i++) {
    printf("%d ", find_min(arr, i, i + L - 1));
  }

  printf("\n"); // Print a newline at the end
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum difference between the tallest and shortest tree when choosing K trees
int min_diff(int *h, int n, int k) {
  // Sort the heights of the trees in ascending order
  qsort(h, n, sizeof(int), 
        (int(*)(const void*, const void*)) 
        (int) (long) (void(*)(const void*, const void*)) 
        (void*) (long) memcmp);

  // Calculate the minimum difference
  int min_diff = h[n - 1] - h[0];
  for (int i = 0; i <= n - k; i++) {
    int diff = h[i + k - 1] - h[i];
    if (diff < min_diff) {
      min_diff = diff;
    }
  }

  return min_diff;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  // Allocate memory for the heights of the trees
  int *h = (int*) malloc(n * sizeof(int));

  // Read the heights of the trees
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }

  // Calculate the minimum difference
  int min_diff_val = min_diff(h, n, k);

  // Print the minimum difference
  printf("%d\n", min_diff_val);

  // Free the allocated memory
  free(h);

  return 0;
}
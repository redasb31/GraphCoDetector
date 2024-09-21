#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum number of vertices in a binary tree
// given the number of leaves at each depth
long long max_vertices(int n, long long *a) {
  // If the number of leaves at depth N is 0, then there is no such tree
  if (a[n] == 0) {
    return -1;
  }
  // Initialize the maximum number of vertices to the number of leaves at depth N
  long long max_v = a[n];
  // Iterate from depth N-1 to 0
  for (int i = n - 1; i >= 0; i--) {
    // If the number of leaves at depth i is greater than the maximum number of vertices
    // at the previous depth, then there is no such tree
    if (a[i] > max_v) {
      return -1;
    }
    // Otherwise, update the maximum number of vertices at depth i
    // by adding the number of vertices at depth i+1
    max_v = max_v + a[i];
  }
  // Return the maximum number of vertices
  return max_v;
}

int main() {
  int n;
  // Read the number of depths
  scanf("%d", &n);
  // Allocate memory for the number of leaves at each depth
  long long *a = (long long *)malloc((n + 1) * sizeof(long long));
  // Read the number of leaves at each depth
  for (int i = 0; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  // Print the maximum number of vertices in the tree
  printf("%lld\n", max_vertices(n, a));
  // Free the allocated memory
  free(a);
  return 0;
}
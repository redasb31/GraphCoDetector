#include <stdio.h>

int main() {
  // Input the number of elements in the sequence
  int n;
  scanf("%d", &n);

  // Input the elements of the sequence
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  // Input the number of queries
  int q;
  scanf("%d", &q);

  // Process each query
  for (int i = 0; i < q; i++) {
    // Input the type of query, starting index, and ending index
    int com, b, e;
    scanf("%d %d %d", &com, &b, &e);

    // Calculate the minimum or maximum element based on the query type
    int min_max = A[b]; // Initialize with the first element in the range
    for (int j = b + 1; j < e; j++) {
      if (com == 0) { // Minimum query
        min_max = (A[j] < min_max) ? A[j] : min_max;
      } else { // Maximum query
        min_max = (A[j] > min_max) ? A[j] : min_max;
      }
    }

    // Print the result
    printf("%d\n", min_max);
  }

  return 0;
}
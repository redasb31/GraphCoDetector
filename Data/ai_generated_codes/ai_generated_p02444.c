#include <stdio.h>

int main() {
  // Input: n (number of elements), a_i (array elements), q (number of queries), b_i, m_i, e_i (query parameters)
  int n, q, i, j, b, m, e;

  // Read the number of elements
  scanf("%d", &n);

  // Declare an array to store the elements
  int a[n];

  // Read the elements of the array
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Read the number of queries
  scanf("%d", &q);

  // Process each query
  for (i = 0; i < q; i++) {
    // Read the query parameters
    scanf("%d %d %d", &b, &m, &e);

    // Perform the rotation operation
    for (j = 0; j < (e - b); j++) {
      int temp = a[b + j];
      a[b + j] = a[b + ((j + (e - m)) % (e - b))];
      a[b + ((j + (e - m)) % (e - b))] = temp;
    }
  }

  // Print the rotated array
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
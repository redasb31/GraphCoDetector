#include <stdio.h>

int main() {
  // Input: number of elements in the array
  int n;
  scanf("%d", &n);

  // Input: array elements
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Input: number of queries
  int q;
  scanf("%d", &q);

  // Process each query
  for (int i = 0; i < q; i++) {
    // Input: start and end indices for the reverse operation
    int b, e;
    scanf("%d %d", &b, &e);

    // Reverse the specified elements
    for (int j = b, k = e - 1; j < k; j++, k--) {
      int temp = a[j];
      a[j] = a[k];
      a[k] = temp;
    }
  }

  // Output: reversed array elements
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
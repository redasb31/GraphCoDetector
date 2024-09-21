#include <stdio.h>

int main() {
  // n: number of elements in A
  int n;
  // q: number of queries
  int q;
  // a: array of integers
  int a[1000];
  // b, e, t: query parameters
  int b, e, t;

  // Read the input
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);

  // Process each query
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", &b, &e, &t);

    // Swap elements within the specified range
    for (int j = b; j < e; j++) {
      // Swap a[j] and a[t + (j - b)]
      int temp = a[j];
      a[j] = a[t + (j - b)];
      a[t + (j - b)] = temp;
    }
  }

  // Print the modified array
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
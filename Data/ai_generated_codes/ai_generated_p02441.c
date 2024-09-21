#include <stdio.h>

int main() {
  // n: Number of elements in the sequence
  int n;
  scanf("%d", &n);

  // a: Array to store the sequence
  int a[n];

  // Read the sequence
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // q: Number of queries
  int q;
  scanf("%d", &q);

  // Process each query
  for (int i = 0; i < q; i++) {
    // b, e, k: Query parameters
    int b, e, k;
    scanf("%d %d %d", &b, &e, &k);

    // count: Counter for the specific value k
    int count = 0;

    // Count the occurrences of k in the specified range
    for (int j = b; j < e; j++) {
      if (a[j] == k) {
        count++;
      }
    }

    // Print the count
    printf("%d\n", count);
  }

  return 0;
}
#include <stdio.h>

int main() {
  // Get the size of the first set.
  int n;
  scanf("%d", &n);

  // Get the elements of the first set.
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Get the size of the second set.
  int m;
  scanf("%d", &m);

  // Get the elements of the second set.
  int b[m];
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  // Initialize the pointers for the two sets.
  int i = 0;
  int j = 0;

  // Iterate through the two sets and print the elements that are in one set but not the other.
  while (i < n && j < m) {
    if (a[i] < b[j]) {
      printf("%d\n", a[i]);
      i++;
    } else if (a[i] > b[j]) {
      printf("%d\n", b[j]);
      j++;
    } else {
      // If the elements are equal, skip them.
      i++;
      j++;
    }
  }

  // Print the remaining elements in the first set.
  while (i < n) {
    printf("%d\n", a[i]);
    i++;
  }

  // Print the remaining elements in the second set.
  while (j < m) {
    printf("%d\n", b[j]);
    j++;
  }

  return 0;
}
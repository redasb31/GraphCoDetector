#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input: number of integers
  int n;
  scanf("%d", &n);

  // Input: array of integers
  int *a = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Sorting the array
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  // Finding the minimum number of colors
  int colors = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      colors++;
    }
  }

  // Output: minimum number of colors
  printf("%d\n", colors);

  // Freeing the allocated memory
  free(a);

  return 0;
}
#include <stdio.h>

int main() {
  // n: Number of elements in set A
  int n;
  // m: Number of elements in set B
  int m;
  // a: Array to store elements of set A
  int a[200000];
  // b: Array to store elements of set B
  int b[200000];
  // i: Index for iterating through set A
  int i;
  // j: Index for iterating through set B
  int j;

  // Input number of elements in set A
  scanf("%d", &n);
  // Input elements of set A
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  // Input number of elements in set B
  scanf("%d", &m);
  // Input elements of set B
  for (i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }

  // i: Index for iterating through set A
  i = 0;
  // j: Index for iterating through set B
  j = 0;

  // Print elements of the union
  while (i < n || j < m) {
    // If both sets have elements, compare and print the smaller element
    if (i < n && j < m) {
      if (a[i] < b[j]) {
        printf("%d\n", a[i]);
        i++;
      } else if (a[i] > b[j]) {
        printf("%d\n", b[j]);
        j++;
      } else {
        printf("%d\n", a[i]);
        i++;
        j++;
      }
    } 
    // If only set A has elements, print remaining elements of set A
    else if (i < n) {
      printf("%d\n", a[i]);
      i++;
    } 
    // If only set B has elements, print remaining elements of set B
    else {
      printf("%d\n", b[j]);
      j++;
    }
  }

  return 0;
}
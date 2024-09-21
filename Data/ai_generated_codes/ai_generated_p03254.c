#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input the number of children and the total sweets
  int N, x;
  scanf("%d %d", &N, &x);

  // Input the desired number of sweets for each child
  int *a = malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Sort the desired sweets in ascending order
  // (Using bubble sort for simplicity, but better sorting algorithms exist)
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  // Calculate the maximum number of happy children
  int happyChildren = 0;
  int currentSweets = x;
  for (int i = 0; i < N; i++) {
    if (currentSweets >= a[i]) {
      currentSweets -= a[i];
      happyChildren++;
    } else {
      break; // No more children can be satisfied
    }
  }

  // Print the result
  printf("%d\n", happyChildren);

  // Free allocated memory
  free(a);

  return 0;
}
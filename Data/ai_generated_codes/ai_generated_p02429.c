#include <stdio.h>

int main() {
  // n: size of the set S
  int n;
  // k: number of elements in the subset T
  int k;
  // b_i: elements in the subset T
  int b[18];

  // Read input
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &b[i]);
  }

  // Calculate the integer representation of the subset T
  int subset_value = 0;
  for (int i = 0; i < k; i++) {
    subset_value |= (1 << b[i]);
  }

  // Print all subsets of T
  for (int i = 0; i <= subset_value; i++) {
    // Check if i is a subset of T
    if ((i & subset_value) == i) {
      // Print the integer value of the subset
      printf("%d:", i);
      // Print the elements in the subset
      int count = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          if (count > 0) {
            printf(" ");
          }
          printf("%d", j);
          count++;
        }
      }
      printf("\n");
    }
  }

  return 0;
}
#include <stdio.h>

int main() {
  // N: Number of squares
  int N;
  // a: Array storing the integers written on each square
  int a[100];
  // count: Number of squares satisfying both conditions
  int count = 0;

  // Read the number of squares
  scanf("%d", &N);

  // Read the integers written on each square
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Iterate through each square
  for (int i = 1; i <= N; i += 2) { // Check only odd-numbered squares
    // Check if the written integer is also odd
    if (a[i - 1] % 2 != 0) {
      count++;
    }
  }

  // Print the count of squares satisfying both conditions
  printf("%d\n", count);

  return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
  // Read the heap size
  int H;
  scanf("%d", &H);

  // Read the heap elements
  int A[251];
  for (int i = 1; i <= H; i++) {
    scanf("%d", &A[i]);
  }

  // Iterate through each node and print its properties
  for (int i = 1; i <= H; i++) {
    printf("node %d: key = %d", i, A[i]);

    // Calculate parent, left, and right child indices
    int parent = floor(i / 2);
    int left = 2 * i;
    int right = 2 * i + 1;

    // Print parent key if it exists
    if (parent >= 1) {
      printf(", parent key = %d", A[parent]);
    }

    // Print left child key if it exists
    if (left <= H) {
      printf(", left key = %d", A[left]);
    }

    // Print right child key if it exists
    if (right <= H) {
      printf(", right key = %d", A[right]);
    }

    printf(" "); // Print a space at the end of each line
  }

  return 0;
}
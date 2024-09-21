#include <stdio.h>
#include <limits.h>

int main() {
  int N;
  scanf("%d", &N);

  // Calculate 2^N
  int size = 1 << N;

  // Read the array
  int A[size];
  for (int i = 0; i < size; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate maximum sum for each K
  for (int K = 1; K < size; K++) {
    int max_sum = INT_MIN;
    // Iterate through all possible pairs (i, j)
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        // Check if (i or j) <= K
        if ((i | j) <= K) {
          // Update maximum sum
          max_sum = (A[i] + A[j] > max_sum) ? A[i] + A[j] : max_sum;
        }
      }
    }
    printf("%d\n", max_sum);
  }
  return 0;
}
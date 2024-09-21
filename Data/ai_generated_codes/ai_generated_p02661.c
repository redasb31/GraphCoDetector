#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: the number of integers
  int N;
  scanf("%d", &N);

  // A_i and B_i: the lower and upper bounds for X_i
  int *A = (int *)malloc(N * sizeof(int));
  int *B = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }

  // Count the number of possible medians
  int count = 0;
  // If N is odd, the median is the middle element
  if (N % 2 == 1) {
    // Iterate through the possible values for the median
    for (int i = (N / 2); i < N; i++) {
      // If the upper bound of the i-th element is greater than or equal to the lower bound of the (N / 2)-th element, 
      // then the median can take a value between these bounds
      if (B[i] >= A[N / 2]) {
        count++;
      }
    }
  } else {
    // If N is even, the median is the average of the two middle elements
    for (int i = (N / 2) - 1; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        // If the upper bound of the i-th element is greater than or equal to the lower bound of the (N / 2)-th element, 
        // and the upper bound of the j-th element is greater than or equal to the lower bound of the ((N / 2) + 1)-th element,
        // then the median can take a value between these bounds
        if (B[i] >= A[N / 2] && B[j] >= A[N / 2 + 1]) {
          count++;
        }
      }
    }
  }

  // Print the count of possible medians
  printf("%d\n", count);

  // Free the allocated memory
  free(A);
  free(B);

  return 0;
}
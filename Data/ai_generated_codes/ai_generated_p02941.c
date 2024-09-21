#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

int main() {
  int N;
  int A[MAX_N], B[MAX_N];
  int i, j, k;
  long long sum_A, sum_B;

  // Input the number of integers
  scanf("%d", &N);

  // Input the initial values
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Input the target values
  for (i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }

  // Calculate the sum of the initial and target values
  sum_A = 0;
  sum_B = 0;
  for (i = 0; i < N; i++) {
    sum_A += A[i];
    sum_B += B[i];
  }

  // If the sum of the initial values is not equal to the sum of the target values, it is impossible to achieve the objective
  if (sum_A != sum_B) {
    printf("-1\n");
    return 0;
  }

  // Check if the objective can be achieved by repeatedly performing the operation
  int operations = 0;
  for (i = 0; i < N; i++) {
    // If the current value is not equal to the target value, perform the operation
    if (A[i] != B[i]) {
      // Find the index of the next value that needs to be changed
      j = (i + 1) % N;
      while (A[j] == B[j]) {
        j = (j + 1) % N;
      }

      // Find the index of the previous value that needs to be changed
      k = (i - 1 + N) % N;
      while (A[k] == B[k]) {
        k = (k - 1 + N) % N;
      }

      // Perform the operation to change the current value
      A[i] = A[(i - 1 + N) % N] + A[i] + A[(i + 1) % N];

      // Increment the number of operations
      operations++;
    }
  }

  // Output the minimum number of operations required
  printf("%d\n", operations);

  return 0;
}
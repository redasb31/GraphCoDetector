#include <stdio.h>

int main() {
  // Input variables
  int N, Q;
  scanf("%d", &N);

  // Array to store the sequence A
  long long A[100001];
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  scanf("%d", &Q);

  // Input for operations (B, C)
  int B[100001], C[100001];
  for (int i = 0; i < Q; i++) {
    scanf("%d %d", &B[i], &C[i]);
  }

  // Calculate and output the sum S_i after each operation
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i]; // Initial sum calculation
  }
  for (int i = 0; i < Q; i++) {
    // Update sum for the current operation
    for (int j = 0; j < N; j++) {
      if (A[j] == B[i]) {
        sum -= A[j]; // Subtract the old value
        A[j] = C[i]; // Update the value
        sum += A[j]; // Add the new value
      }
    }
    printf("%lld\n", sum); // Print the sum after the current operation
  }

  return 0;
}
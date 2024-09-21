#include <stdio.h>

int main() {
  // Input:
  int N; // Length of the sequence
  scanf("%d", &N);
  int A[N]; // The sequence
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the XOR and sum of all elements up to each index:
  int xorSum[N + 1]; // xorSum[i] = A[0] xor A[1] xor ... xor A[i - 1]
  int sum[N + 1]; // sum[i] = A[0] + A[1] + ... + A[i - 1]
  xorSum[0] = 0;
  sum[0] = 0;
  for (int i = 0; i < N; i++) {
    xorSum[i + 1] = xorSum[i] ^ A[i]; // Calculate XOR
    sum[i + 1] = sum[i] + A[i]; // Calculate sum
  }

  // Count the valid pairs:
  int count = 0;
  for (int l = 1; l <= N; l++) {
    for (int r = l; r <= N; r++) {
      // Check the condition:
      if (xorSum[r] ^ xorSum[l - 1] == sum[r] - sum[l - 1]) {
        count++;
      }
    }
  }

  // Output:
  printf("%d\n", count);

  return 0;
}
#include <stdio.h>

int main() {
  // N: number of materials
  // H, W: target dimensions
  int N, H, W;
  scanf("%d %d %d", &N, &H, &W);

  // A_i, B_i: dimensions of each material
  int A[1000], B[1000];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }

  // Count the number of materials that can produce the target dimensions
  int count = 0;
  for (int i = 0; i < N; i++) {
    // Check if the material can be cut to produce the target dimensions
    if ((A[i] >= H && B[i] >= W) || (A[i] >= W && B[i] >= H)) {
      count++;
    }
  }

  // Print the answer
  printf("%d\n", count);

  return 0;
}
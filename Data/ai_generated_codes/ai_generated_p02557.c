#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int A[200000], B[200000];
  // Read the sequences A and B
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }

  // Check if the condition is possible
  // If any element in B is at the same position in A, the condition is not possible
  int possible = 1;
  for (int i = 0; i < N; i++) {
    if (A[i] == B[i]) {
      possible = 0;
      break;
    }
  }

  if (possible) {
    printf("Yes\n");
    // Output a reordering of B
    // If A[i] == B[i], then we can swap B[i] with the next element B[i+1]
    for (int i = 0; i < N; i++) {
      if (A[i] == B[i] && i < N - 1) {
        int temp = B[i];
        B[i] = B[i + 1];
        B[i + 1] = temp;
        i++; // Skip the next element as it has been swapped
      }
      printf("%d ", B[i]);
    }
    printf("\n");
  } else {
    printf("No\n");
  }

  return 0;
}
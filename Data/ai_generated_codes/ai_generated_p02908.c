#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  // Read the permutations P and Q
  int P[N], Q[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &Q[i]);
  }

  // Calculate the maximum distance
  int distance = 0;
  for (int i = 0; i < N; i++) {
    // If P[i] and Q[i] are different, we can choose to make A[i] = P[i] and B[i] = Q[i] or vice versa
    if (P[i] != Q[i]) {
      distance++;
    }
  }

  printf("%d\n", distance);

  return 0;
}
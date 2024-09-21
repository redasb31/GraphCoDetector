#include <stdio.h>

int main() {
  // Input variables
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);

  // Train information
  int L[200000], R[200000];
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &L[i], &R[i]);
  }

  // Query information
  int p[100000], q[100000];
  for (int i = 0; i < Q; i++) {
    scanf("%d %d", &p[i], &q[i]);
  }

  // Process each query
  for (int i = 0; i < Q; i++) {
    int count = 0; // Count of trains within the section
    // Iterate through all trains
    for (int j = 0; j < M; j++) {
      // Check if the train runs strictly within the section
      if (p[i] <= L[j] && R[j] <= q[i]) {
        count++;
      }
    }
    printf("%d\n", count); // Print the count for the current query
  }

  return 0;
}
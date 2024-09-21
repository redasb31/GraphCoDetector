#include <stdio.h>

int main() {
  // N: Number of members
  int N;
  // A[i]: Immediate boss of member i
  int A[200000];
  // SubordinateCount[i]: Number of immediate subordinates of member i
  int SubordinateCount[200000] = {0};

  // Read input
  scanf("%d", &N);
  for (int i = 2; i <= N; i++) {
    scanf("%d", &A[i]);
    // Increment subordinate count of the boss
    SubordinateCount[A[i]]++;
  }

  // Print the number of immediate subordinates for each member
  for (int i = 1; i <= N; i++) {
    printf("%d\n", SubordinateCount[i]);
  }

  return 0;
}
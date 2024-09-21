#include <stdio.h>

int main() {
  // N: Number of balls
  // K: Maximum number of different integers
  int N, K;
  scanf("%d %d", &N, &K);

  // Array to store the count of each integer
  int count[N + 1] = {0};
  
  // Read the integers on the balls
  for (int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    count[A]++;
  }

  // Calculate the minimum number of balls to rewrite
  int min_rewrite = N;
  int current_count = 0;

  // Sort the count array in descending order (optional for efficiency)
  // ... (Implementation of sorting algorithm)

  // Iterate through the count array and find the minimum number of balls to rewrite
  for (int i = 1; i <= N; i++) {
    current_count += count[i];
    if (current_count >= K) {
      min_rewrite = N - current_count;
      break;
    }
  }

  // Print the minimum number of balls to rewrite
  printf("%d\n", min_rewrite);

  return 0;
}
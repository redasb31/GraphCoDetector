#include <stdio.h>

int main() {
  // Read input
  int N;
  scanf("%d", &N);
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Count odd and even numbers
  int odd_count = 0;
  int even_count = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 0) {
      even_count++;
    } else {
      odd_count++;
    }
  }

  // Calculate the maximum number of actions
  int max_actions = 0;
  if (odd_count > 0 && even_count > 0) {
    // If both odd and even numbers exist, we can take actions until only one type remains
    max_actions = (odd_count < even_count) ? odd_count : even_count;
  }

  // Output the result
  printf("%d\n", max_actions);

  return 0;
}
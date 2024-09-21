#include <stdio.h>
#include <limits.h>

int main() {
  int k;
  scanf("%d", &k);

  // Store the group sizes for each round
  int a[k];
  for (int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate the minimum number of children needed
  long long min_n = 1; // Start with at least one child
  for (int i = 0; i < k; i++) {
    // To ensure two children remain after the i-th round,
    // there must be at least (a[i] - 1) * 2 + 1 children before
    // the i-th round, to leave (a[i] - 1) * 2 children after the round.
    min_n = (a[i] - 1) * 2 + 1;
  }

  // Calculate the maximum number of children possible
  long long max_n = INT_MAX;
  for (int i = 0; i < k; i++) {
    // The maximum number of children possible is constrained by the
    // largest group size, as all children must be divisible by this size
    max_n = (max_n / a[i]) * a[i];
    // If max_n is less than the minimum number of children needed,
    // the situation is impossible
    if (max_n < min_n) {
      max_n = -1;
      break;
    }
  }

  // If the situation is impossible, print -1
  if (max_n == -1) {
    printf("-1\n");
  } else {
    // Otherwise, print the minimum and maximum number of children
    printf("%lld %lld\n", min_n, max_n);
  }

  return 0;
}
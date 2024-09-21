#include <stdio.h>

int main() {
  // N: the length of the sequences
  int N;
  scanf("%d", &N);

  // a and b: the two integer sequences
  int a[10000], b[10000];

  // Read the input sequences
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  // Calculate the difference between the sums of a and b
  int diff = 0;
  for (int i = 0; i < N; i++) {
    diff += a[i] - b[i];
  }

  // If the difference is even and divisible by 2, then it's possible to make the sequences equal
  if (diff % 2 == 0 && diff >= 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
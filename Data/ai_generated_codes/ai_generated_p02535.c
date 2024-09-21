#include <stdio.h>

int main() {
  long long A, B, C, D;

  // Input the ranges
  scanf("%lld %lld %lld %lld", &A, &B, &C, &D);

  // Check if there's an overlap
  if (B >= C && A <= D) {
    printf("Yes\n"); // There's an overlap
  } else {
    printf("No\n"); // No overlap
  }

  return 0;
}
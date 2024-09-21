#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input the coordinates of A, B, and C
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  // Calculate the distances between A and B, and B and C
  int distance_ab = abs(a - b);
  int distance_bc = abs(b - c);

  // Check if A and C can communicate directly or indirectly
  if (distance_ab <= d && distance_bc <= d) {
    printf("Yes\n"); // A and C can communicate indirectly
  } else if (abs(a - c) <= d) {
    printf("Yes\n"); // A and C can communicate directly
  } else {
    printf("No\n"); // A and C cannot communicate
  }

  return 0;
}
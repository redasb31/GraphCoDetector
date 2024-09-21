#include <stdio.h>

int main() {
  // Input the road connections
  int a1, b1, a2, b2, a3, b3;
  scanf("%d %d", &a1, &b1);
  scanf("%d %d", &a2, &b2);
  scanf("%d %d", &a3, &b3);

  // Check if all towns can be reached from each other
  // using a simple connectivity check 
  if ((a1 == a2 && b1 == b3) || (a1 == a3 && b1 == b2) || (a2 == a3 && b2 == b1)) {
    // All towns are connected 
    printf("YES\n"); // We can visit all towns by traversing each road exactly once
  } else {
    // If not connected, we can't visit all towns by traversing each road exactly once
    printf("NO\n");
  }
  return 0;
}
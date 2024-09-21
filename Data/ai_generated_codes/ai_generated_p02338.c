#include <stdio.h>

#define MOD 1000000007

int main() {
  int n, k; // n: number of balls, k: number of boxes
  scanf("%d %d", &n, &k);

  // If there are more balls than boxes, it's impossible to put all balls in
  if (n > k) {
    printf("0\n");
    return 0;
  }

  // If there are fewer balls than boxes, only one arrangement is possible
  if (n < k) {
    printf("1\n");
    return 0;
  }

  // If the number of balls and boxes are equal, there's only one possible arrangement
  if (n == k) {
    printf("1\n");
    return 0;
  }
  
  return 0;
}
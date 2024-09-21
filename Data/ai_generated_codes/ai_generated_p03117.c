#include <stdio.h>
#include <math.h>

int main() {
  // Input: Number of red balls and blue balls
  long long R, B;
  scanf("%lld %lld", &R, &B);

  // Calculate the maximum number of boxes
  long long K = 1; 
  // Calculate the maximum possible number of boxes
  for (long long i = 1; i <= R && i <= B; i++) {
    // if both red and blue balls are available
    if (R % i == 0 && B % i == 0) {
      // Check if the current value of i gives a greater value of K
      K = i;
    }
  }

  // Output the maximum possible number of boxes
  printf("%lld\n", K);

  return 0;
}
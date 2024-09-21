#include <stdio.h>
#include <math.h>

int main() {
  // Read the number of red and blue balls.
  long long R, B;
  scanf("%lld %lld", &R, &B);

  // Calculate the maximum possible number of boxes.
  // The maximum number of boxes is the sum of the number of red and blue balls.
  // This is because we can have a box for each red ball and a box for each blue ball.
  long long max_boxes = R + B;

  // We can also have boxes with combinations of red and blue balls.
  // The maximum number of combinations is the minimum of the number of red balls and the number of blue balls.
  // This is because we can only have as many combinations as the smaller number of balls.
  long long combinations = fmin(R, B);

  // The total maximum number of boxes is the sum of the number of boxes with single balls and the number of boxes with combinations.
  long long K = max_boxes + combinations;

  // Print the maximum number of boxes.
  printf("%lld\n", K);

  return 0;
}
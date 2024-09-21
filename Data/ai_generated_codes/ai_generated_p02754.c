#include <stdio.h>
#include <math.h>

int main() {
  long long N, A, B;
  scanf("%lld %lld %lld", &N, &A, &B);

  // Calculate the number of complete cycles (A blue balls + B red balls) within N balls.
  long long cycles = N / (A + B);

  // Calculate the number of blue balls in the complete cycles.
  long long blueBalls = cycles * A;

  // Calculate the remaining balls that don't form a complete cycle.
  long long remainingBalls = N % (A + B);

  // If the remaining balls include some blue balls.
  if (remainingBalls > A) {
    blueBalls += A;
  } else {
    // Add the number of blue balls in the remaining balls.
    blueBalls += remainingBalls;
  }

  printf("%lld\n", blueBalls);

  return 0;
}
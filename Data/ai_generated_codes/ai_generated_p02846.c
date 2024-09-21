#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables for the input values
  long long int T1, T2, A1, A2, B1, B2;

  // Read the input values
  scanf("%lld %lld\n%lld %lld\n%lld %lld", &T1, &T2, &A1, &A2, &B1, &B2);

  // Calculate the distance Takahashi travels in one cycle
  long long int TakahashiCycleDistance = T1 * A1 + T2 * A2;

  // Calculate the distance Aoki travels in one cycle
  long long int AokiCycleDistance = T1 * B1 + T2 * B2;

  // Calculate the difference in distance traveled per cycle
  long long int distanceDifference = abs(TakahashiCycleDistance - AokiCycleDistance);

  // Check if the difference in distance is zero, meaning they meet infinitely many times
  if (distanceDifference == 0) {
    printf("infinity\n");
    return 0;
  }

  // Calculate the greatest common divisor of the cycle distances
  long long int gcd = __gcd(TakahashiCycleDistance, AokiCycleDistance);

  // Calculate the number of times they will meet
  long long int meetings = distanceDifference / gcd;

  // Print the number of times they will meet
  printf("%lld\n", meetings);

  return 0;
}
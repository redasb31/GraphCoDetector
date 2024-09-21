#include <stdio.h>
#include <math.h>

int main() {
  long long int N;

  // Read input until N is 0
  while (scanf("%lld", &N) != EOF && N != 0) {
    // Calculate the area of the tank's base (N * N)
    long long int baseArea = N * N;

    // Calculate the area of the circle formed by the liquid
    long long int circleArea = (long long int)(M_PI * (N / 2) * (N / 2));

    // Calculate the area of the tank's base that is covered by the liquid
    long long int coveredArea = baseArea - circleArea;

    // Calculate the number of FDP tiles needed
    long long int tilesNeeded = baseArea - coveredArea;

    // Print the number of tiles
    printf("%lld\n", tilesNeeded);
  }

  return 0;
}
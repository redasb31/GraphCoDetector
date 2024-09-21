#include <stdio.h>
#include <limits.h>

int main() {
  // Declare variables to store flight times
  int P, Q, R;

  // Read flight times from standard input
  scanf("%d %d %d", &P, &Q, &R);

  // Calculate the flight time for each possible route
  int route1 = P + Q; // A -> B -> C
  int route2 = P + R; // A -> C -> B
  int route3 = Q + R; // B -> C -> A
  int route4 = Q + P; // B -> A -> C
  int route5 = R + P; // C -> A -> B
  int route6 = R + Q; // C -> B -> A

  // Find the minimum flight time
  int minTime = INT_MAX; // Initialize minTime to maximum possible value
  minTime = (route1 < minTime) ? route1 : minTime;
  minTime = (route2 < minTime) ? route2 : minTime;
  minTime = (route3 < minTime) ? route3 : minTime;
  minTime = (route4 < minTime) ? route4 : minTime;
  minTime = (route5 < minTime) ? route5 : minTime;
  minTime = (route6 < minTime) ? route6 : minTime;

  // Print the minimum flight time
  printf("%d\n", minTime);

  return 0;
}
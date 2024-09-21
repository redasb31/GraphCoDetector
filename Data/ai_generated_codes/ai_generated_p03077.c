#include <stdio.h>

int main() {
  // Input: Number of people, vehicle capacities
  long long N, A, B, C, D, E;
  scanf("%lld", &N);
  scanf("%lld", &A);
  scanf("%lld", &B);
  scanf("%lld", &C);
  scanf("%lld", &D);
  scanf("%lld", &E);

  // Calculate the minimum time for each segment of the journey
  long long time1 = (N + A - 1) / A; // Time to travel from City 1 to 2
  long long time2 = (N + B - 1) / B; // Time to travel from City 2 to 3
  long long time3 = (N + C - 1) / C; // Time to travel from City 3 to 4
  long long time4 = (N + D - 1) / D; // Time to travel from City 4 to 5
  long long time5 = (N + E - 1) / E; // Time to travel from City 5 to 6

  // Calculate the total minimum time
  long long totalTime = time1 + time2 + time3 + time4 + time5;

  // Output the result
  printf("%lld\n", totalTime);

  return 0;
}
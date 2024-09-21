#include <stdio.h>

int main() {
  // Input variables
  long long A, B, V, W, T;

  // Read input
  scanf("%lld %lld\n%lld %lld\n%lld", &A, &V, &B, &W, &T);

  // Calculate the distance "it" can travel in T seconds
  long long distance_it = V * T;

  // Calculate the distance the other child can travel in T seconds
  long long distance_other = W * T;

  // Calculate the maximum distance "it" can travel to reach the other child
  long long max_distance = distance_it + A;

  // Calculate the maximum distance the other child can travel to avoid "it"
  long long max_other_distance = distance_other + B;

  // Check if "it" can catch the other child
  if (max_distance >= max_other_distance) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
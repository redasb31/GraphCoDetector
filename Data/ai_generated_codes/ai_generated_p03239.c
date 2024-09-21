#include <stdio.h>
#include <limits.h>

int main() {
  int N, T; // N: number of routes, T: time limit
  scanf("%d %d", &N, &T);

  int min_cost = INT_MAX; // Initialize minimum cost to maximum integer value

  // Loop through each route
  for (int i = 0; i < N; i++) {
    int c, t; // c: cost of the route, t: time taken for the route
    scanf("%d %d", &c, &t);

    // Check if the route is within the time limit
    if (t <= T) {
      // Update minimum cost if the current route is cheaper
      if (c < min_cost) {
        min_cost = c;
      }
    }
  }

  // Print the minimum cost if there is a valid route
  if (min_cost != INT_MAX) {
    printf("%d\n", min_cost);
  } else {
    // Print "TLE" if there is no valid route
    printf("TLE\n");
  }

  return 0;
}
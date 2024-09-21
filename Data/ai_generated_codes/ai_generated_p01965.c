#include <stdio.h>
#include <limits.h>

int main() {
  int N; // Number of houses
  scanf("%d", &N);

  // Array to store carrying costs between houses
  int d[N - 1];
  for (int i = 0; i < N - 1; i++) {
    scanf("%d", &d[i]);
  }

  // Array to store growing costs for each house
  int g[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &g[i]);
  }

  // Initialize minimum cost array with growing costs
  int min_cost[N];
  for (int i = 0; i < N; i++) {
    min_cost[i] = g[i];
  }

  // Dynamic programming approach to calculate minimum cost
  for (int i = 1; i < N; i++) {
    // Calculate the cost of supplying from the previous house
    int cost_from_previous = min_cost[i - 1] + d[i - 1];

    // Compare the cost from the previous house with the current growing cost
    if (cost_from_previous < min_cost[i]) {
      min_cost[i] = cost_from_previous;
    }
  }

  // Print the minimum cost for supplying to all houses
  printf("%d\n", min_cost[N - 1]);

  return 0;
}
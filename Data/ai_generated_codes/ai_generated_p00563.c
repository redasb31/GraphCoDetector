#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000
#define MAX_M 1000000

int N, M;
int C[MAX_N];
int cost[MAX_M];

// Recursive function to calculate the minimum cost for a given color
int min_cost(int l, int r, int color) {
  // Base case: rope length is 2
  if (l + 1 == r) {
    if (C[l] == color) return 0;
    else return 1;
  }

  // Find the midpoint
  int mid = (l + r) / 2;

  // Calculate the minimum cost for both halves
  int left_cost = min_cost(l, mid, color);
  int right_cost = min_cost(mid, r, color);

  // Calculate the cost of combining the two halves
  int combine_cost = 0;
  if (mid - l > r - mid) {
    // If left half is larger, combine right half with itself
    combine_cost = min_cost(mid, r, color);
  } else {
    // If right half is larger, combine left half with itself
    combine_cost = min_cost(l, mid, color);
  }

  // Return the minimum cost
  return min(left_cost + combine_cost, right_cost + combine_cost);
}

int main() {
  // Read input
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }

  // Calculate minimum cost for each color
  for (int i = 1; i <= M; i++) {
    cost[i] = min_cost(0, N, i);
    printf("%d\n", cost[i]);
  }

  return 0;
}
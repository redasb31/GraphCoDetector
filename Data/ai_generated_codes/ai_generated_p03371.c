#include <stdio.h>
#include <limits.h>

int main() {
  // Input the prices and the number of pizzas needed
  int A, B, C, X, Y;
  scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

  // Calculate the cost of buying AB-pizzas and rearranging them
  int ab_cost = 2 * C * (X + Y);

  // Calculate the cost of buying A-pizzas and B-pizzas directly
  int direct_cost = A * X + B * Y;

  // Determine the minimum cost
  int min_cost = (ab_cost < direct_cost) ? ab_cost : direct_cost;

  // Output the minimum cost
  printf("%d\n", min_cost);

  return 0;
}
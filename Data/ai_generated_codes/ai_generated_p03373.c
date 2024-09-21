#include <stdio.h>

int main() {
  // Declare variables for pizza prices and quantities
  int A, B, C, X, Y;

  // Read the input values
  scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

  // Calculate the cost of buying pizzas directly
  int direct_cost = A * X + B * Y;

  // Calculate the cost of buying AB-pizzas and rearranging them
  int ab_cost = 2 * C * (X + Y); // Buy enough AB-pizzas to make X A-pizzas and Y B-pizzas

  // Determine the minimum cost
  int min_cost = (direct_cost < ab_cost) ? direct_cost : ab_cost;

  // Print the minimum cost
  printf("%d\n", min_cost);

  return 0;
}
#include <stdio.h>

int main() {
  // Declare variables to store input values
  int N, A, B;

  // Read input values from the user
  scanf("%d %d %d", &N, &A, &B);

  // Calculate the cost of each plan
  int plan1Cost = A * N; // Cost of plan 1
  int plan2Cost = B; // Cost of plan 2

  // Find the minimum cost between the two plans
  int minCost = (plan1Cost < plan2Cost) ? plan1Cost : plan2Cost;

  // Print the minimum cost
  printf("%d\n", minCost);

  return 0;
}
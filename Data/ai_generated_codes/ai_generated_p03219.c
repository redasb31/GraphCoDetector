#include <stdio.h>

int main() {
  // Declare variables for train fare (X) and bus fare (Y)
  int X, Y;

  // Read input values for train fare and bus fare
  scanf("%d %d", &X, &Y);

  // Calculate the cost of the bus fare with the special ticket (half price)
  int bus_fare = Y / 2;

  // Calculate the total cost of travelling from Station A to Station C
  int total_cost = X + bus_fare;

  // Print the total cost
  printf("%d\n", total_cost);

  return 0;
}
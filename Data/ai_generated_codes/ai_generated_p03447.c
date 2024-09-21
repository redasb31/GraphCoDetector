#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int X, A, B;

  // Read the input values from the user
  scanf("%d", &X); // Amount of yen you have
  scanf("%d", &A); // Price of the cake
  scanf("%d", &B); // Price of each donut

  // Calculate the amount remaining after buying the cake
  int remaining = X - A;

  // Calculate the number of donuts you can buy
  int num_donuts = remaining / B;

  // Calculate the amount remaining after buying donuts
  remaining = remaining - (num_donuts * B);

  // Print the amount remaining
  printf("%d\n", remaining);

  return 0;
}
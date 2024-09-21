#include <stdio.h>

int main() {
  // Declare variables to store the input values
  int N, X, T;

  // Read the input values from the user
  scanf("%d %d %d", &N, &X, &T);

  // Calculate the number of batches needed to make N takoyaki
  int batches = (N + X - 1) / X;

  // Calculate the total time required to make N takoyaki
  int total_time = batches * T;

  // Print the total time required
  printf("%d\n", total_time);

  return 0;
}
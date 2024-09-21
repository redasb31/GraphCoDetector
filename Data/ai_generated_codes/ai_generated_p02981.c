#include <stdio.h>

int main() {
  // Declare variables to store input values
  int N, A, B;

  // Read input values from standard input
  scanf("%d %d %d", &N, &A, &B);

  // Calculate the total cost of travelling by train
  int trainCost = N * A;

  // Calculate the minimum total travel expense
  int minCost = (trainCost < B) ? trainCost : B;

  // Print the minimum total travel expense
  printf("%d\n", minCost);

  return 0;
}
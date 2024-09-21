#include <stdio.h>

int main() {
  // N: number of items
  // M: number of discount tickets
  int N, M;
  scanf("%d %d", &N, &M);

  // A: array of prices for each item
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the minimum cost
  long long int total_cost = 0;
  for (int i = 0; i < N; i++) {
    // Calculate the number of tickets to use for the current item
    int num_tickets = 0;
    while (A[i] > 1 && M > 0) {
      A[i] /= 2;
      num_tickets++;
      M--;
    }
    // Add the cost of the current item to the total cost
    total_cost += A[i];
  }

  // Print the minimum cost
  printf("%lld\n", total_cost);

  return 0;
}
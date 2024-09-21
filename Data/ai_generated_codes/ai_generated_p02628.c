#include <stdio.h>

int main() {
  // N: Number of fruit types
  // K: Number of fruit types to buy
  int N, K;
  scanf("%d %d", &N, &K);

  // p: Array to store the price of each fruit type
  int p[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }

  // Sort the prices in ascending order
  // (We don't need a full sorting algorithm, just finding the K smallest elements is enough)
  for (int i = 0; i < K; i++) {
    // Find the minimum price among the remaining fruits
    int min_index = i;
    for (int j = i + 1; j < N; j++) {
      if (p[j] < p[min_index]) {
        min_index = j;
      }
    }
    // Swap the minimum price with the current position
    int temp = p[i];
    p[i] = p[min_index];
    p[min_index] = temp;
  }

  // Calculate the total price of the K cheapest fruits
  int total_price = 0;
  for (int i = 0; i < K; i++) {
    total_price += p[i];
  }

  printf("%d\n", total_price);

  return 0;
}
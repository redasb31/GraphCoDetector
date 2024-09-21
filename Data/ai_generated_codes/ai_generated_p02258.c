#include <stdio.h>
#include <limits.h>

int main() {
  // n: number of time points
  int n;
  scanf("%d", &n);

  // R: array to store the currency rates
  int R[n];

  // Read the currency rates
  for (int i = 0; i < n; i++) {
    scanf("%d", &R[i]);
  }

  // min_price: minimum currency rate encountered so far
  int min_price = INT_MAX;

  // max_profit: maximum profit obtained so far
  int max_profit = INT_MIN;

  // Iterate over the currency rates
  for (int i = 0; i < n; i++) {
    // Update the minimum price if a lower price is found
    if (R[i] < min_price) {
      min_price = R[i];
    }

    // Calculate the profit for the current rate
    int profit = R[i] - min_price;

    // Update the maximum profit if a higher profit is found
    if (profit > max_profit) {
      max_profit = profit;
    }
  }

  // Print the maximum profit
  printf("%d\n", max_profit);

  return 0;
}
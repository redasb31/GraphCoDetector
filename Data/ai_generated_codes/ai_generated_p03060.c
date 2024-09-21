#include <stdio.h>

int main() {
  // N: Number of gems
  int N;
  scanf("%d", &N);

  // V: Array to store the value of each gem
  int V[20];
  // C: Array to store the cost of each gem
  int C[20];

  // Read the value and cost of each gem
  for (int i = 0; i < N; i++) {
    scanf("%d", &V[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }

  // max_profit: Stores the maximum profit
  int max_profit = 0;

  // Iterate through all possible combinations of gems
  for (int i = 0; i < (1 << N); i++) {
    // sum_value: Stores the sum of the values of chosen gems
    int sum_value = 0;
    // sum_cost: Stores the sum of the costs of chosen gems
    int sum_cost = 0;

    // Iterate through each gem
    for (int j = 0; j < N; j++) {
      // If the j-th bit of i is set, then the j-th gem is chosen
      if (i & (1 << j)) {
        sum_value += V[j];
        sum_cost += C[j];
      }
    }

    // Update the maximum profit
    max_profit = (sum_value - sum_cost) > max_profit ? (sum_value - sum_cost) : max_profit;
  }

  // Print the maximum profit
  printf("%d\n", max_profit);

  return 0;
}
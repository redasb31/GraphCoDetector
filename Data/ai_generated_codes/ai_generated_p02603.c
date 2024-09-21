#include <stdio.h>

int main() {
  // N: Number of days
  int N;
  // A: Array storing the stock prices for each day
  int A[80];

  // Read the number of days
  scanf("%d", &N);

  // Read the stock prices for each day
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize the maximum amount of money to the initial amount
  int max_money = 1000;
  // Initialize the number of stocks to 0
  int num_stocks = 0;

  // Iterate through the days
  for (int i = 0; i < N; i++) {
    // If the current price is lower than the next price, buy stocks
    if (i < N - 1 && A[i] < A[i + 1]) {
      // Calculate the maximum number of stocks that can be bought
      int max_buy = max_money / A[i];
      // Buy the maximum number of stocks
      num_stocks += max_buy;
      // Update the amount of money
      max_money -= max_buy * A[i];
    }
    // If the current price is higher than the next price, sell stocks
    else if (i < N - 1 && A[i] > A[i + 1]) {
      // Sell all the stocks
      max_money += num_stocks * A[i];
      // Update the number of stocks
      num_stocks = 0;
    }
    // If it's the last day, sell all stocks
    else if (i == N - 1) {
      // Sell all the stocks
      max_money += num_stocks * A[i];
      // Update the number of stocks
      num_stocks = 0;
    }
  }

  // Print the maximum possible amount of money
  printf("%d\n", max_money);

  return 0;
}
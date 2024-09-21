#include <stdio.h>

int main() {
  int n, i, j, price, maxCoins, minExpenses, currentCoins, currentExpenses;
  int coins[5001]; // Array to store the maximum number of coins for each price

  // Initialize the array with -1, indicating no coin can be collected for each price
  for (i = 0; i <= 5000; i++) {
    coins[i] = -1;
  }

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break; // End of input
    }
    maxCoins = 0;
    minExpenses = 0;
    currentCoins = 0;
    currentExpenses = 0;

    // Iterate through each souvenir shop
    for (i = 0; i < n; i++) {
      scanf("%d", &price);
      // Iterate through all possible prices (from 0 to the current price)
      for (j = 0; j <= price; j++) {
        // If the price is a multiple of 500, we can get one more coin
        if (j % 500 == 0) {
          // If we can collect more coins with this price, update the maximum coins and expenses
          if (coins[j] + 1 > maxCoins) {
            maxCoins = coins[j] + 1;
            minExpenses = currentExpenses;
          }
          // If we can collect the same number of coins with less expenses, update the minimum expenses
          else if (coins[j] + 1 == maxCoins && currentExpenses < minExpenses) {
            minExpenses = currentExpenses;
          }
        }
        // If we have enough coins for the current price, we can get one more coin and update the coins and expenses
        if (coins[price - j] >= 0 && j != 0) {
          if (coins[price] < coins[price - j] + 1) {
            coins[price] = coins[price - j] + 1;
            currentExpenses = currentExpenses + j;
          }
        }
      }
    }

    printf("%d %d\n", maxCoins, minExpenses);
  }
  return 0;
}
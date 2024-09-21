#include <stdio.h>

int main() {
  // Declare variable to store the input value
  int n;

  // Read the input value from the user
  scanf("%d", &n);

  // Declare variables to store the number of coins for each denomination
  int coins25 = 0, coins10 = 0, coins5 = 0, coins1 = 0;

  // Calculate the number of coins for each denomination
  coins25 = n / 25;
  n %= 25;

  coins10 = n / 10;
  n %= 10;

  coins5 = n / 5;
  n %= 5;

  coins1 = n;

  // Calculate the total number of coins
  int totalCoins = coins25 + coins10 + coins5 + coins1;

  // Print the total number of coins
  printf("%d\n", totalCoins);

  return 0;
}